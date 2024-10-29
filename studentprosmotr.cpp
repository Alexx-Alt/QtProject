#include "studentprosmotr.h"
#include "ui_studentprosmotr.h"
#include "jwt.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QDateTime>
#include <QUuid>
#include <QJsonDocument>
#include <QJsonObject>

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
void StudentProsmotr::displayStudentsForTeacher() {
    // Получаем токен из настроек
    QSettings settings("MyApp", "MyAppName");
    QString token = settings.value("userToken").toString();

    if (token.isEmpty()) {
        qDebug() << "Токен отсутствует. Пользователь не авторизован.";
        return;
    }

    // Получаем секретный ключ из защищенного источника
    QString secretKey = getUserSecretKey(token);

    QJsonObject payload;
    if (JWT::decode(token, payload, secretKey)) {
        QString username = payload["username"].toString();
        qint64 expirationTime = payload["exp"].toVariant().toLongLong();

        // Проверка срока действия токена
        if (QDateTime::currentSecsSinceEpoch() > expirationTime) {
            qDebug() << "Срок действия токена истек";
            return;
        }

        // Получаем teacher_id по имени пользователя
        QSqlQuery query;
        query.prepare("SELECT id FROM users WHERE username = ?");
        query.addBindValue(username);

        if (!query.exec() || !query.next()) {
            qDebug() << "Ошибка получения teacher_id преподавателя:" << query.lastError().text();
            return;
        }

        int teacherId = query.value(0).toInt();

        // Запрашиваем список студентов для teacher_id
        QSqlQuery studentQuery;
        studentQuery.prepare("SELECT us.username "
                             "FROM student_teacher st "
                             "JOIN users us ON st.student_id = us.id "
                             "WHERE st.teacher_id = ?");
        studentQuery.addBindValue(teacherId);

        if (studentQuery.exec()) {
            QString studentList;
            while (studentQuery.next()) {
                studentList += studentQuery.value("username").toString() + "\n";
            }

            if (!studentList.isEmpty()) {
                ui->studentListLabel->setText("Студенты:\n" + studentList);
            } else {
                ui->studentListLabel->setText("У данного преподавателя нет студентов.");
            }
        } else {
            qDebug() << "Ошибка получения списка студентов:" << studentQuery.lastError().text();
        }
    } else {
        qDebug() << "Ошибка декодирования токена";
    }
}
// Вспомогательная функция для получения секретного ключа
QString StudentProsmotr::getUserSecretKey(const QString &token) {
    QStringList parts = token.split('.');
    if (parts.size() != 3) {
        qDebug() << "Неверный формат токена";
        return QString();
    }

    QByteArray payloadJson = QByteArray::fromBase64(parts[1].toUtf8());
    QJsonDocument payloadDoc = QJsonDocument::fromJson(payloadJson);
    if (payloadDoc.isNull()) {
        qDebug() << "Ошибка декодирования payload токена";
        return QString();
    }

    QJsonObject payload = payloadDoc.object();
    QString username = payload["username"].toString();

    if (username.isEmpty()) {
        qDebug() << "Токен не содержит имя пользователя";
        return QString();
    }

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

