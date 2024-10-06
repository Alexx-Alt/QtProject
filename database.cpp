#include "database.h"
#include <QDebug>
#include <QSqlError>

Database::Database(const QString &host, int port, const QString &dbName, const QString &user, const QString &password) {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(host);
    db.setPort(port);
    db.setDatabaseName(dbName);
    db.setUserName(user);
    db.setPassword(password);
}

Database::~Database() {
    close(); // Закрываем подключение при уничтожении объекта
}

bool Database::open() {
    if (!db.open()) {
        qDebug() << "Ошибка подключения к базе данных:" << db.lastError().text();
        return false;
    }
    qDebug() << "Подключение успешно!";
    return true;
}

void Database::close() {
    db.close();
}

QSqlDatabase Database::getDatabase() const {
    return db;
}
