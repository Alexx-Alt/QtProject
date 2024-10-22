#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"


#include <QCryptographicHash>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSettings>
#include <QDateTime>
#include <QUuid>
#include <QDebug>


login::login(QWidget *parent)
    : QWidget(parent), ui(new Ui::login)
{
    ui->setupUi(this);
    ui->registerframe->hide();

}

login::~login()
{
    delete ui;

}

// Кнопка входа
void login::on_LoginButton_clicked()
{
    const QString username = ui->NameLabel2->text();
    const QString password = ui->PasswordLabel2->text();
    usernameCons = username; // Сохраняем имя пользователя

    // Создание запроса для проверки пользователя
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec()) {
        showError("Ошибка выполнения запроса: " + query.lastError().text());
        return;
    }

    // Проверка, нашелся ли пользователь
    if (query.next()) {
        const QString storedHash = query.value(0).toString(); // Получаем хранимый хэш пароля
        if (storedHash == hashPassword(password)) { // Сравниваем с введенным паролем
            QMessageBox::information(this, "Успех", "Вы успешно вошли в систему!");

            // Генерация токена (можно использовать UUID или другой метод)
            QString token = generateToken();
            qDebug() << token;

            // Сохранение токена и даты создания
            saveToken(token);
            // Сохранение токена в таблице users
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE users SET token = ? WHERE username = ?");
            updateQuery.addBindValue(token);
            updateQuery.addBindValue(username);

            if (!updateQuery.exec()) {
                showError("Ошибка сохранения токена: " + updateQuery.lastError().text());
                return;
            }

            auto *mainWindow = new MainWindow(usernameCons);
            mainWindow->show(); // Открываем главное окно
            close(); // Закрываем окно входа
        } else {
            showWarning("Неверный пароль.");
        }
    } else {
        showWarning("Пользователь не найден.");
    }
}
// Генерация токена
QString login::generateToken()
{
    // Простой пример токена. В реальном приложении используйте более безопасный метод.
    return QUuid::createUuid().toString();
}

// Сохранение токена в QSettings
void login::saveToken(const QString &token)
{
    QSettings settings("MyApp", "MyAppName");
    settings.setValue("userToken", token);
    settings.setValue("username", ui->NameLabel2->text());
    settings.setValue("tokenCreationDate", QDateTime::currentDateTime()); // Сохранение даты создания токена

}

// Кнопка показывания формы регистрации
void login::on_RegistrationButton_clicked()
{
    ui->registerframe->show();
}

// Кнопка завершения регистрации
void login::on_loginButton_clicked()
{

    const QString username = ui->NameLabel->text();
    const QString password = ui->PasswordLabel->text();
    const QString email = ui->EmailLabel->text();
    // Проверка на пустые значения
    if (username.isEmpty()) {
        showWarning("Имя пользователя не может быть пустым.");
        return;
    }
    if (password.isEmpty()) {
        showWarning("Пароль не может быть пустым.");
        return;
    }
    if (email.isEmpty()) {
        showWarning("Электронная почта не может быть пустой.");
        return;
    }
    // Проверка уникальности имени пользователя
    if (!isUsernameUnique(username)) {
        showWarning("Имя пользователя уже занято.");
        return;
    }

    // Регистрация пользователя
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, email) VALUES (?, ?, ?)");
    query.addBindValue(username);
    query.addBindValue(hashPassword(password)); // Вставьте свою функцию хэширования
    query.addBindValue(email);

    if (!query.exec()) {
        showError("Ошибка регистрации: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Регистрация прошла успешно!");
        ui->registerframe->hide();
    }
    ui->PasswordLabel->clear();
    ui->NameLabel->clear();
    ui->EmailLabel->clear();
    ui->PasswordLabel->clear();
}

// Кнопка входа после регистрации
void login::on_backregister_clicked()
{
    ui->registerframe->hide();
    ui->NameLabel->clear();
    ui->EmailLabel->clear();

}

// Функция для хэширования пароля
QString login::hashPassword(const QString &password)
{
    return QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
}

// Функция для отображения сообщений об ошибках
void login::showError(const QString &message)
{
    QMessageBox::critical(this, "Ошибка", message);
}

// Функция для отображения предупреждений
void login::showWarning(const QString &message)
{
    QMessageBox::warning(this, "Внимание", message);
}

// Функция для проверки уникальности имени пользователя
bool login::isUsernameUnique(const QString &username)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE username = ?");
    query.addBindValue(username);
    if (!query.exec() || !query.next()) {
        showError("Ошибка проверки имени пользователя: " + query.lastError().text());
        return false;
    }
    return query.value(0).toInt() == 0; // Если 0, значит имя пользователя уникально
}
