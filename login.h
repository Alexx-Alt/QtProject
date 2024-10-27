#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QSettings>


namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    void loadInterfaceForRole(const QString &username);

private slots:
    void on_LoginButton_clicked();
    void on_RegistrationButton_clicked();
    void on_loginButton_clicked();
    void on_backregister_clicked();
    QString generateSecretKey();

    QString getUserSecretKey(const QString &username);


private:
    Ui::login *ui;
    QString hashPassword(const QString &password);
    void showError(const QString &message);
    void showWarning(const QString &message);
    bool isUsernameUnique(const QString &username);
    QString generateJwtToken(const QString &username, const QString &secretKey);
    void saveToken(const QString &token);
    QString usernameCons;


    int getUserRole(const QString &username);

};

#endif // LOGIN_H
