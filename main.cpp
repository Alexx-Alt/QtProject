#include "mainwindow.h"
#include "database.h"
#include "login.h"
#include "jwt.h"


#include <QApplication>
#include <QtSql>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QtGui>
#include <QSettings>
#include <QDateTime>
#include <QtDebug>

// Функция для получения секретного ключа пользователя
QString getUserSecretKey(const QString &username) {
    QSqlQuery query;
    query.prepare("SELECT secret_key FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }

    // Если ключ не найден, генерируем новый
    QString newSecretKey = QUuid::createUuid().toString(QUuid::WithoutBraces);

    query.prepare("UPDATE users SET secret_key = :secret_key WHERE username = :username");
    query.bindValue(":secret_key", newSecretKey);
    query.bindValue(":username", username);

    if (query.exec()) {
        return newSecretKey;
    } else {
        qDebug() << "Ошибка сохранения нового секретного ключа:" << query.lastError().text();
        return QString();
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Создание объекта Database и подключение к базе данных
    Database db("127.0.0.1", 3306, "lern", "root", "Pocket_2564");

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось подключиться к базе данных.");
        return -1;
    }

    QSettings settings("MyApp", "MyAppName");
    QString storedToken = settings.value("userToken").toString();
    QString username;

    if (!storedToken.isEmpty()) {
            // Проверяем токен
            try {
                QString secretKey = getUserSecretKey(username);
                QJsonObject payload;
                JWT::decode(storedToken, payload, secretKey);

                // Извлекаем username из payload
                username = payload["username"].toString();

                qint64 exp = payload["exp"].toVariant().toLongLong();
                QDateTime expirationDate = QDateTime::fromSecsSinceEpoch(exp);

                if (expirationDate > QDateTime::currentDateTime()) {
                    // Токен действителен, открываем главное окно
                    MainWindow *mainWindow = new MainWindow(username);
                    mainWindow->show();
                    return a.exec();
                } else {
                    qDebug() << "Токен истек";
                }
            } catch (const std::exception& e) {
                qDebug() << "Ошибка при проверке токена:" << e.what();
            }
        }





    // Если токен недействителен, отсутствует или произошла ошибка, показываем окно входа
    login l;
    l.show();

    return a.exec();
}
