#include "mainwindow.h"
#include "login.h"
#include "database.h"

#include <QApplication>
#include <QtSql>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QtGui>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    login l;
    // Создание объекта Database и подключение к базе данных
    Database db("127.0.0.1", 3306, "lernv1", "root", "Pocket_2564");

    if (!db.open()) {
        return -1; // Завершаем программу в случае ошибки подключения
    }



    w.show();
    return a.exec();


}

