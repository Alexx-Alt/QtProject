#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

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

    void showError(const QString &message);

    void showWarning(const QString &message);

    bool isUsernameUnique(const QString &username);

private:
    Ui::login *ui;
    QString hashPassword(const QString &password);
    void openMainWindow();
    QString usernameCons; // Переменная для хранения имени пользователя

};

#endif // LOGIN_H
