#include "mainpage.h"
#include "ui_mainpage.h"
#include "jwt.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QDateTime>
#include <QUuid>
#include <QJsonDocument>
#include <QJsonObject>

MainPage::MainPage(const QString &username, QWidget *parent)
    : QFrame(parent), ui(new Ui::MainPage)
    , currentUserName(username)
{
    ui->setupUi(this);
    //ui->welcomeLabel->setText("q");

    int userId = getUserIdByUsername(currentUserName);

    fetchUserLevelAndExperience();
    fetchCompletedCoursesAndLessons(userId);
    fetchCompletedTestsCount(userId);
    updateUserExperience(userId);
}

MainPage::~MainPage()
{
    delete ui;
}
//функция для отображения уровня и кол-во очков пользователя
void MainPage::fetchUserLevelAndExperience() {
    QSettings settings("MyApp", "MyAppName");
    QString token = settings.value("userToken").toString();

    if (token.isEmpty()) {
        qDebug() << "Токен отсутствует. Пользователь не авторизован.";
        // Перенаправление на страницу входа
        return;
    }

    // Получаем секретный ключ из защищенного источника
    QString secretKey = getUserSecretKey(token);

    QJsonObject payload;
    if (JWT::decode(token, payload, secretKey)) {
        QString username = payload["username"].toString();
        qint64 expirationTime = payload["exp"].toVariant().toLongLong();

        // Проверка срока действия токена
        if (QDateTime::currentSecsSinceEpoch() > expirationTime) {
            qDebug() << "Срок действия токена истек";
            // Логика для обновления токена или перенаправления на страницу входа
            return;
        }

        QSqlQuery query;
        query.prepare("SELECT level, experience_points FROM users WHERE username = ?");
        query.addBindValue(username);

        if (query.exec() && query.next()) {
            int level = query.value("level").toInt();
            int experiencePoints = query.value("experience_points").toInt();

            ui->welcomeLabel->setText("Добро пожаловать, " + username + "! Текущий уровень: " + QString::number(level));
            ui->experienceLabel->setText("Очки опыта: " + QString::number(experiencePoints));
        } else {
            qDebug() << "Ошибка получения данных пользователя:" << query.lastError().text();
        }
    } else {
        qDebug() << "Токен недействителен";
        // Логика для обработки недействительного токена
    }
}
// Вспомогательная функция для получения секретного ключа
QString MainPage::getUserSecretKey(const QString &token) {
    QStringList parts = token.split('.');
    if (parts.size() != 3) {
        qDebug() << "Неверный формат токена";
        return QString();
    }

    QByteArray payloadJson = QByteArray::fromBase64(parts[1].toUtf8());
    QJsonDocument payloadDoc = QJsonDocument::fromJson(payloadJson);
    if (payloadDoc.isNull()) {
        qDebug() << "Ошибка декодирования payload токена";
        return QString();
    }

    QJsonObject payload = payloadDoc.object();
    QString username = payload["username"].toString();

    if (username.isEmpty()) {
        qDebug() << "Токен не содержит имя пользователя";
        return QString();
    }

    QSqlQuery query;
    query.prepare("SELECT secret_key FROM users WHERE username = ?");
    query.addBindValue(username);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    } else {
        qDebug() << "Ошибка получения секретного ключа:" << query.lastError().text();
        return QString();
    }
}
//функция для отображения кол-во выполненых курсов и уроков пользователя
void MainPage::fetchCompletedCoursesAndLessons(int userId) {
    // Получение количества пройденных курсов
    QSqlQuery queryCourses;
    queryCourses.prepare("SELECT COUNT(DISTINCT course_id) AS completed_courses FROM user_progress WHERE user_id = ? AND completed = TRUE;");
    queryCourses.addBindValue(userId);

    if (queryCourses.exec() && queryCourses.next()) {
        int completedCourses = queryCourses.value(0).toInt();
        ui->completedCoursesLabel->setText("Пройденные курсы: " + QString::number(completedCourses));
    } else {
        qDebug() << "Ошибка получения количества пройденных курсов:" << queryCourses.lastError().text();
    }

    // Получение количества пройденных уроков
    QSqlQuery queryLessons;
    queryLessons.prepare("SELECT COUNT(DISTINCT lesson_id) AS completed_lessons FROM user_progress WHERE user_id = ? AND completed = TRUE;");
    queryLessons.addBindValue(userId);

    if (queryLessons.exec() && queryLessons.next()) {
        int completedLessons = queryLessons.value(0).toInt();
        ui->completedLessonsLabel->setText("Пройденные уроки: " + QString::number(completedLessons));
    } else {
        qDebug() << "Ошибка получения количества пройденных уроков:" << queryLessons.lastError().text();
    }
}

void MainPage::fetchCompletedTestsCount(int userId) {
    QSqlQuery query;
    query.prepare("SELECT test_count FROM test_results WHERE user_id = ?");
    query.addBindValue(userId);

    if (query.exec() && query.next()) {
        int completedTests = query.value("test_count").toInt();
        ui->completedTestsLabel->setText("Пройденные тесты: " + QString::number(completedTests));
    } else {
        qDebug() << "Ошибка получения количества пройденных тестов:" << query.lastError().text();
    }
}
//функция получения Id пользователя по его username
int MainPage::getUserIdByUsername(const QString &username) {
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

void MainPage::updateUserExperience(int userId) {
    QSqlQuery query;
    // Получение текущих уровня и опыта
    query.prepare("SELECT level, experience_points FROM users WHERE id = ?");
    query.addBindValue(userId);

    if (!query.exec() || !query.next()) {
        qDebug() << "Ошибка получения текущего уровня и опыта:" << query.lastError().text();
        return;
    }

    int currentLevel = query.value("level").toInt();
    int currentExperience = query.value("experience_points").toInt();

    // Опыт, необходимый для повышения уровня
    const int experienceForNextLevel = 100;

    // Повышение уровня, если текущий опыт превышает требуемый
    while (currentExperience >= experienceForNextLevel) {
        ++currentLevel;
        currentExperience -= experienceForNextLevel;  // Сбрасываем 100 очков после повышения уровня
    }

    // Обновление уровня и оставшихся очков опыта пользователя в базе данных
    query.prepare("UPDATE users SET level = ?, experience_points = ? WHERE id = ?");
    query.addBindValue(currentLevel);
    query.addBindValue(currentExperience);  // Обновляем оставшиеся очки
    query.addBindValue(userId);

    if (!query.exec()) {
        qDebug() << "Ошибка обновления уровня:" << query.lastError().text();
    } else {
        qDebug() << "Уровень успешно обновлен! Текущий уровень:" << currentLevel;
    }
}
