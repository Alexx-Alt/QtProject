#include "studentprosmotr.h"
#include "ui_studentprosmotr.h"
#include "jwt.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QDebug>

StudentProsmotr::StudentProsmotr(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::StudentProsmotr)
{
    ui->setupUi(this);
    displayStudentsForTeacher();
}

StudentProsmotr::~StudentProsmotr()
{
    delete ui;
}

// Функция для декодирования base64Url в QByteArray
QByteArray StudentProsmotr::base64UrlDecode(const QString &base64Url) {
    QString base64 = base64Url;
    base64.replace('-', '+').replace('_', '/');
    while (base64.length() % 4 != 0) {
        base64.append('=');
    }
    return QByteArray::fromBase64(base64.toUtf8());
}

void StudentProsmotr::displayStudentsForTeacher() {
    QSettings settings("MyApp", "MyAppName");
    QString storedToken = settings.value("userToken").toString();
    qDebug() << "Stored Token:" << storedToken;

    QString username;

    if (!storedToken.isEmpty()) {
        try {
            // Разделяем токен на части
            QStringList tokenParts = storedToken.split('.');
            if (tokenParts.size() != 3) {
                throw std::runtime_error("Неверный формат токена");
            }

            // Декодируем полезную нагрузку (payload)
            QByteArray payloadJson = base64UrlDecode(tokenParts[1]);
            QJsonDocument payloadDoc = QJsonDocument::fromJson(payloadJson);

            if (payloadDoc.isNull()) {
                throw std::runtime_error("Ошибка декодирования токена");
            }

            QJsonObject payload = payloadDoc.object();
            username = payload["username"].toString();
            qDebug() << "Decoded Username:" << username;

            if (username.isEmpty()) {
                throw std::runtime_error("Токен не содержит имя пользователя");
            }

            QString secretKey = getUserSecretKey(username);

            // Проверка подписи токена
            if (!JWT::verify(storedToken, secretKey)) {
                throw std::runtime_error("Подпись токена недействительна");
            }

            qint64 exp = payload["exp"].toVariant().toLongLong();
            QDateTime expirationDate = QDateTime::fromSecsSinceEpoch(exp);

            if (expirationDate <= QDateTime::currentDateTime()) {
                throw std::runtime_error("Токен истек");
            }
        } catch (const std::exception &e) {
            qDebug() << "Ошибка при проверке токена:" << e.what();
            return; // Завершаем функцию, если токен недействителен
        }
        // Запрашиваем ID учителя по его username
        QSqlQuery query;
        query.prepare("SELECT id FROM users WHERE username = :username");
        query.bindValue(":username", username);

        if (!query.exec() || !query.next()) {
            QMessageBox::critical(this, "Ошибка", "Не удалось получить ID учителя: " + query.lastError().text());
            return;
        }

        int teacherId = query.value(0).toInt();

        // Выполняем запрос для получения списка студентов
        query.prepare("SELECT us.username FROM student_teacher st "
                      "JOIN users us ON st.student_id = us.id "
                      "WHERE st.teacher_id = :teacher_id");
        query.bindValue(":teacher_id", teacherId);

        if (!query.exec()) {
            QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос: " + query.lastError().text());
            return;
        }

        // Заполняем список студентов в интерфейсе
        while (query.next()) {
            QString studentName = query.value(0).toString();
            ui->studentListWidget->addItem(studentName); // предполагается, что studentListWidget - это QListWidget
        }
    }
}
// Вспомогательная функция для получения секретного ключа пользователя
QString StudentProsmotr::getUserSecretKey(const QString &username) {
    QSqlQuery query;
    query.prepare("SELECT secret_key FROM users WHERE username = ?");
    query.addBindValue(username);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    } else {
        qDebug() << "Ошибка получения секретного ключа:" << query.lastError().text();
        return QString();
    }
}
