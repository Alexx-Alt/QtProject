#include "mainpage.h"
#include "ui_mainpage.h"

#include <QSqlQuery>
#include <QSqlError>

MainPage::MainPage(const QString &username, QWidget *parent)
    : QFrame(parent), ui(new Ui::MainPage)
    , currentUserName(username)
{
    ui->setupUi(this);
    //ui->welcomeLabel->setText("q");

    int userId = getUserIdByUsername(currentUserName);

    fetchUserLevelAndExperience(userId);
    fetchCompletedCoursesAndLessons(userId);
    fetchCompletedTestsCount(userId);
    updateUserExperience(userId);
    testforum();

}

MainPage::~MainPage()
{
    delete ui;
}
//функция для отображения уровня и кол-во очков пользователя
void MainPage::fetchUserLevelAndExperience(int userId) {
    QSqlQuery query;
    query.prepare("SELECT level, experience_points FROM users WHERE id = ?");
    query.addBindValue(userId);

    if (query.exec() && query.next()) {
        int level = query.value("level").toInt();
        int experiencePoints = query.value("experience_points").toInt();

        // Отображение на главной странице
        ui->welcomeLabel->setText("Добро пожаловать, " + currentUserName + "! Текущий уровень: " + QString::number(level));
        ui->experienceLabel->setText("Очки опыта: " + QString::number(experiencePoints));

    } else {
        qDebug() << "Ошибка получения уровня и очков опыта:" << query.lastError().text();
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
void MainPage::testforum(){

    QSqlQuery query;
    QString str;
    query.prepare("SELECT text FROM lern.forum_question"
                        "join users "
                        "ON forum_question.author_id = users.id " );
    if(query.exec()){
        str = query.value(0).toString();
    }
    ui->testlabel->setText(str);

}
