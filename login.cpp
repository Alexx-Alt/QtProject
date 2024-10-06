#include "login.h"
#include "ui_login.h"
#include "mainwindow.h" // Подключаем класс MainWindow

#include <QCryptographicHash>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    ui->registerframe->hide();

}

login::~login()
{
    delete ui;
}


void login::on_loginButton_clicked()
{

    QString username = ui->NameLabel->text();
    QString password = ui->PasswordLabel->text();
    QString email = ui->EmailLabel->text();
    // Регистрация пользователя
    QSqlQuery query;
    query.prepare("INSERT INTO student (Username, PasswordS, Email) VALUES (?, ?, ?)");
    query.addBindValue(username);
    query.addBindValue(hashPassword(password)); // Вставьте свою функцию хэширования
    query.addBindValue(email);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка регистрации: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Регистрация прошла успешно!");
    }
    ui->registerframe->hide();




}
// Функция для хэширования пароля
QString login::hashPassword(const QString &password) {
    return QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
}




void login::on_RegistrationButton_clicked()
{
    ui->registerframe->show();
}


void login::on_backregister_clicked()
{
    ui->registerframe->hide();
    ui->NameLabel->clear();
    ui->EmailLabel->clear();
    ui->PasswordLabel->clear();
}


void login::on_LoginButton_clicked()
{
    QString username = ui->NameLabel2->text();
    QString password = ui->PasswordLabel2->text();

    // Создание запроса для проверки пользователя
    QSqlQuery query;
    query.prepare("SELECT PasswordS FROM student WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса: " + query.lastError().text());
        return;
    }
    // Проверка, нашелся ли пользователь
    if (query.next()) {
        QString storedHash = query.value(0).toString(); // Получаем хранимый хэш пароля
        if (storedHash == hashPassword(password)) { // Сравниваем с введенным паролем
            QMessageBox::information(this, "Успех", "Вы успешно вошли в систему!");
            // Здесь можно закрыть окно входа и открыть главное окно приложения
            this->close(); // Закрываем окно входа
            openMainWindow(); // Открываем главное окно
        } else {
            QMessageBox::warning(this, "Ошибка", "Неверный пароль.");
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Пользователь не найден.");
    }

}
void login::openMainWindow() {
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show(); // Показываем главное окно
}

