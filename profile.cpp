#include "profile.h"
#include "ui_profile.h"

#include <QSqlQuery>
#include <QSqlError>

Profile::Profile(const QString &username, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::Profile)
    , currentUserName(username)
{
    ui->setupUi(this);
    int userId = getUserIdByUsername(currentUserName);
    fetchUserLevelAndExperience(userId);
    fetchuserregs(userId);
}

Profile::~Profile()
{
    delete ui;
}
//функция получения Id пользователя по его username
int Profile::getUserIdByUsername(const QString &username) {
    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE username = ?"); // Предполагается, что имя пользователя хранится в поле username
    query.addBindValue(username);

    if (query.exec() && query.next()) {
        return query.value(0).toInt(); // Возвращаем ID пользователя
    } else {
        qDebug() << "Ошибка получения ID пользователя:" << query.lastError().text();
        return -1; // Возвращаем -1 в случае ошибки или если пользователь не найден
    }
}
void Profile::fetchUserLevelAndExperience(int userId) {
    QSqlQuery query;
    query.prepare("SELECT level FROM users WHERE id = ?");
    query.addBindValue(userId);

    if (query.exec() && query.next()) {
        int level = query.value("level").toInt();
        ui->userlabel->setText("Имя: " + currentUserName + "! Текущий уровень: " + QString::number(level));
    } else {
        qDebug() << "Ошибка получения уровня и очков опыта:" << query.lastError().text();
    }

}
void Profile::fetchuserregs(int userId)
{
    QSqlQuery query;
    query.prepare("SELECT ts.title "
                  "FROM tegs_storage ts "
                  "WHERE ts.user_id = ? " );

}
