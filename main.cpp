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
    //MainWindow w;

    login l;
    // Создание объекта Database и подключение к базе данных
    Database db("127.0.0.1", 3306, "lern", "root", "Pocket_2564");

    if (!db.open()) {
        return -1; // Завершаем программу в случае ошибки подключения
    }
    QSettings settings("MyApp", "MyAppName"); // Замените на свои названия
    QString storedToken = settings.value("userToken").toString();
    QDateTime tokenCreationDate = settings.value("tokenCreationDate").toDateTime();
    QString username = settings.value("username").toString(); // Получаем имя пользователя из настроек
    qDebug() << username;

    // Проверяем действительность токена (30 дней)
    if (!storedToken.isEmpty() && tokenCreationDate.isValid() && tokenCreationDate.addDays(30) > QDateTime::currentDateTime()) {
        // Токен действителен, теперь проверим токен в базе данных
        QSqlQuery query;
        query.prepare("SELECT token FROM users WHERE username = ?");
        query.addBindValue(username);

        if (query.exec() && query.next()) {
            QString dbToken = query.value(0).toString(); // Получаем токен из базы данных

            if (storedToken == dbToken) {
                // Токены совпадают, открываем главное окно с именем пользователя
                MainWindow *mainWindow = new MainWindow(username); // Передаем имя пользователя
                mainWindow->show();
                qDebug() << username;
            } else {
                qDebug() << "Токены не совпадают, показываем окно входа";
                l.show();
            }
        } else {
            qDebug() << "Ошибка при получении токена из базы данных или пользователь не найден";
            l.show();
        }
    } else {
        qDebug() << "Токен недействителен или отсутствует, показываем окно входа";
        l.show();
    }

    return a.exec();
}

