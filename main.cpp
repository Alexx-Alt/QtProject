#include "mainwindow.h"
#include "database.h"
#include "login.h"


#include <QApplication>
#include <QtSql>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QtGui>
#include <QSettings>
#include <QDateTime>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "Application started";

    Database db("127.0.0.1", 3306, "lern", "root", "Pocket_2564");
    if (!db.open()) {
        qDebug() << "Database connection failed";
        return -1;
    }
    qDebug() << "Database connected successfully";

    QSettings settings("MyApp", "MyAppName");
    QString storedToken = settings.value("userToken").toString();

    if (!storedToken.isEmpty()) {
        qDebug() << "Token found";
        QJsonObject payload;
        QString secret = "your_secret_key";
        if (JWT::decode(storedToken, payload, secret)) {
            qDebug() << "Token decoded successfully";
            qint64 expirationTime = payload["exp"].toVariant().toLongLong();
            QDateTime expiresAt = QDateTime::fromSecsSinceEpoch(expirationTime);

            if (expiresAt > QDateTime::currentDateTime()) {
                QString username = payload["username"].toString();
                qDebug() << "Creating MainWindow for user:" << username;
                MainWindow *mainWindow = new MainWindow(username);
                mainWindow->show();
                qDebug() << "MainWindow should be visible now";
            } else {
                qDebug() << "Token expired, showing login window";
                login *l = new login();
                l->show();
            }
        } else {
            qDebug() << "Token decode failed, showing login window";
            login *l = new login();
            l->show();
        }
    } else {
        qDebug() << "No token found, showing login window";
        login *l = new login();
        l->show();
    }

    qDebug() << "Entering event loop";
    return a.exec();
}
