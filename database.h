#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QString>

class Database {
public:
    Database(const QString &host, int port, const QString &dbName, const QString &user, const QString &password);
    ~Database();

    bool open();
    void close();
    QSqlDatabase getDatabase() const;

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
