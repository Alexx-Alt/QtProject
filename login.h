#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QSettings>
#include "jwt.h" // Убедитесь, что у вас есть этот заголовочный файл

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_LoginButton_clicked();
    void on_RegistrationButton_clicked();
    void on_loginButton_clicked();
    void on_backregister_clicked();

private:
    Ui::login *ui;
    QString hashPassword(const QString &password);
    void showError(const QString &message);
    void showWarning(const QString &message);
    bool isUsernameUnique(const QString &username);
    QString generateJwtToken(int userId, const QString &username);
    void saveToken(const QString &token);
    QString usernameCons;
};

#endif // LOGIN_H
