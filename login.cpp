#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "jwt.h"


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
// Генерация секретного ключа
QString login::generateSecretKey()
{
    return QUuid::createUuid().toString(QUuid::WithoutBraces);
}
// Функция для получения или создания секретного ключа пользователя
QString login::getUserSecretKey(const QString &username) {
    QSqlQuery query;
    query.prepare("SELECT secret_key FROM users WHERE username = ?");
    query.addBindValue(username);

    if (query.exec() && query.next()) {
        QString secretKey = query.value(0).toString();
        if (!secretKey.isEmpty()) {
            return secretKey;  // Возвращаем существующий ключ
        }
    }

    // Если ключ не найден или пустой, генерируем новый
    QString newSecretKey = QUuid::createUuid().toString(QUuid::WithoutBraces);

    query.prepare("UPDATE users SET secret_key = ? WHERE username = ?");
    query.addBindValue(newSecretKey);
    query.addBindValue(username);

    if (query.exec()) {
        qDebug() << "Новый секретный ключ сохранен для пользователя:" << username;
        return newSecretKey;
    } else {
        qDebug() << "Ошибка сохранения нового секретного ключа:" << query.lastError().text();
        return QString();
    }
}

void login::on_LoginButton_clicked()
{
    const QString username = ui->NameLabel2->text();
    const QString password = ui->PasswordLabel2->text();

    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec()) {
        showError("Ошибка выполнения запроса: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        const QString storedHash = query.value(0).toString();
        if (storedHash == hashPassword(password)) {
            QString secretKey = getUserSecretKey(username);
            if (secretKey.isEmpty()) {
                showError("Не удалось получить секретный ключ");
                return;
            }

            // Создаем JWT токен
            QJsonObject payload;
            payload["username"] = username;
            payload["exp"] = QDateTime::currentDateTime().addDays(30).toSecsSinceEpoch();

            QString token = JWT::encode(payload, secretKey);

            // Сохраняем токен
            QSettings settings("MyApp", "MyAppName");
            settings.setValue("userToken", token);

            QMessageBox::information(this, "Успех", "Вы успешно вошли в систему!");

            auto *mainWindow = new MainWindow(username);
            mainWindow->show();
            close();
        } else {
            showWarning("Неверный пароль.");
        }
    } else {
        showWarning("Пользователь не найден.");
    }
}
// Генерация токена
QString login::generateJwtToken(const QString &username, const QString &secretKey)
{
    QJsonObject payload;
    payload["username"] = username;
    payload["iat"] = QDateTime::currentDateTime().toSecsSinceEpoch(); // Время создания токена
    payload["exp"] = QDateTime::currentDateTime().addDays(30).toSecsSinceEpoch(); // Срок действия токена (30 дней)

    // Дополнительные поля, если нужно
    // payload["role"] = "user";

    // Создаем JWT токен
    return JWT::encode(payload, secretKey);
}

// Сохранение токена в QSettings
void login::saveToken(const QString &token)
{
    QSettings settings("MyApp", "MyAppName");
    settings.setValue("userToken", token);


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
