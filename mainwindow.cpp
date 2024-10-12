#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myframe.h"

#include <QPropertyAnimation>
#include <QPropertyAnimation>
#include <QSplitter>
#include <QGridLayout>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

// Конструктор
MainWindow::MainWindow(const QString &username, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), currentUserName(username)
{
    ui->setupUi(this);

    MyFrame *frame = new MyFrame(this);
    frame->hide();

    setFixedSize(1800, 1000); // Установите фиксированный размер окна

    QPixmap pixmap(":/img/house.png");
    QPixmap book(":/img/book.png");
    QPixmap course(":/img/course.png");
    ui->frame->hide();
    ui->testframe->hide();
    ui->courseframe->hide();

    ui->menulabel->setPixmap(pixmap);
    ui->booklabel->setPixmap(book);
    ui->courselabel->setPixmap(course);
    ui->menulabel->setScaledContents(true);
    ui->booklabel->setScaledContents(true);
    ui->courselabel->setScaledContents(true);
    ui->widget->setFixedWidth(1);                                   // Устанавливаем фиксированную ширину
    ui->widget_2->setFixedHeight(1);                                   // Устанавливаем фиксированную ширину
    ui->widget->setStyleSheet("background-color: gray;");           // Устанавливаем цвет линии
    ui->widget_2->setStyleSheet("background-color: gray;");           // Устанавливаем цвет линии

    // Заголовок
    ui->welcomeLabel->setText("Добро пожаловать, " + currentUserName + "!");

    // Получаем ID пользователя
    int userId = getUserIdByUsername(currentUserName);

    if (userId != -1) {
        // Получаем пройденные курсы и уроки
        fetchCompletedCoursesAndLessons(userId);

        fetchUserLevelAndExperience(userId);  // Получаем уровень и очки опыта
        loadAvailableTests(); // Загружаем доступные тесты для прохождения
        fetchCompletedTestsCount(userId);

    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось найти пользователя.");
    }
}

// Деструктор
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updateUserExperience(int userId, int pointsEarned) {
    QSqlQuery query;

    // Обновление очков опыта пользователя
    query.prepare("UPDATE users SET experience_points = experience_points + ? WHERE id = ?");
    query.addBindValue(pointsEarned);
    query.addBindValue(userId);

    if (!query.exec()) {
        qDebug() << "Ошибка обновления очков опыта:" << query.lastError().text();
        return;
    } else {
        qDebug() << "Очки опыта успешно обновлены!";
    }

    // Получение текущих уровня и опыта
    query.prepare("SELECT level, experience_points FROM users WHERE id = ?");
    query.addBindValue(userId);

    if (!query.exec() || !query.next()) {
        qDebug() << "Ошибка получения текущего уровня и опыта:" << query.lastError().text();
        return;
    }

    int currentLevel = query.value("level").toInt();
    int currentExperience = query.value("experience_points").toInt();

    // Формула для расчета опыта, необходимого для следующего уровня
    // Например, каждый уровень требует больше опыта: 100 * (текущий_уровень ^ 1.5)
    int experienceForNextLevel = static_cast<int>(100 * std::pow(currentLevel, 1.5));

    // Повышение уровня, если текущий опыт превышает требуемый
    while (currentExperience >= experienceForNextLevel) {
        ++currentLevel;
        currentExperience -= experienceForNextLevel;  // Сбрасываем текущий опыт после повышения уровня
        experienceForNextLevel = static_cast<int>(100 * std::pow(currentLevel, 1.5));  // Обновляем опыт для следующего уровня
    }

    // Обновление уровня пользователя в базе данных
    query.prepare("UPDATE users SET level = ?, experience_points = ? WHERE id = ?");
    query.addBindValue(currentLevel);
    query.addBindValue(currentExperience);  // Сбрасываем очки до нового уровня
    query.addBindValue(userId);

    if (!query.exec()) {
        qDebug() << "Ошибка обновления уровня:" << query.lastError().text();
    } else {
        qDebug() << "Уровень успешно обновлен! Текущий уровень:" << currentLevel;
    }
}

// Отображение домашней страницы
void MainWindow::on_pushButton_clicked()
{

    frame->hide();
    ui->testframe->hide();
    ui->frame->show();
    ui->courseframe->hide();
    ui->upmenuHome->setStyleSheet("font: 700 14pt;");
    ui->upmenuTest->setStyleSheet("font: 14pt;");
}

// Функция загрузки доступных тестов
void MainWindow::loadAvailableTests()
{
    QSqlQuery query;
    query.prepare("SELECT id, title FROM tests");

    if (query.exec()) {
        while (query.next()) {
            int testId = query.value("id").toInt();
            QString testTitle = query.value("title").toString();

            ui->testComboBox->addItem(testTitle, testId);  // Добавляем тесты в ComboBox для выбора
        }
    } else {
        qDebug() << "Ошибка загрузки доступных тестов:" << query.lastError().text();
    }
}

// Обработчик нажатия кнопки "Пройти тест"
void MainWindow::on_startTestButton_clicked()
{
    int selectedTestId = ui->testComboBox->currentData().toInt();  // Получаем выбранный тест из ComboBox
    if (selectedTestId > 0) {
        currentTestId = selectedTestId;
        currentQuestionIndex = 0;
        correctAnswers = 0;

        // Загружаем вопросы теста
        loadTestQuestions();
    }
}

// Загрузка вопросов теста
void MainWindow::loadTestQuestions()
{
    QSqlQuery query;
    query.prepare("SELECT id, question_text FROM test_questions WHERE test_id = ?");
    query.addBindValue(currentTestId);

    questionIds.clear();
    questions.clear();

    if (query.exec()) {
        while (query.next()) {
            int questionId = query.value("id").toInt();
            QString questionText = query.value("question_text").toString();

            questionIds.append(questionId);
            questions.append(questionText);
        }

        if (!questions.isEmpty()) {
            showQuestion(0);  // Отображаем первый вопрос
        }
    } else {
        qDebug() << "Ошибка загрузки вопросов теста:" << query.lastError().text();
    }
}

// Отображение текущего вопроса
void MainWindow::showQuestion(int index)
{
    if (index < questions.size()) {
        ui->questionLabel->setText(questions[index]);
        ui->answerInput->clear();
        ui->nextQuestionButton->setEnabled(true);
        ui->finishTestButton->setEnabled(false);
    }
}

// Обработчик нажатия кнопки "Следующий вопрос"
void MainWindow::on_nextQuestionButton_clicked()
{
    // Получаем текст текущего вопроса и ответ, который выбрал пользователь
    QString selectedAnswer = ui->answerInput->text().trimmed();  // Поле для ввода ответа
    QString correctAnswer;

    if (currentQuestionIndex < questionIds.size()) {
        // Проверяем правильность ответа
        QSqlQuery query;
        query.prepare("SELECT correct_answer FROM test_questions WHERE id = ?");
        query.addBindValue(questionIds[currentQuestionIndex]);

        if (query.exec() && query.next()) {
            correctAnswer = query.value(0).toString().trimmed();
        } else {
            qDebug() << "Ошибка получения правильного ответа:" << query.lastError().text();
        }

        // Проверяем, совпадает ли ответ пользователя с правильным ответом
        if (selectedAnswer == correctAnswer) {
            ++correctAnswers;  // Увеличиваем количество правильных ответов
            ui->statusLabel->setText("Правильный ответ!");
        } else {
            ui->statusLabel->setText("Неправильный ответ.");
        }
    }

    // Переход к следующему вопросу
    ++currentQuestionIndex;

    // Если вопросы закончились, завершаем тест
    if (currentQuestionIndex >= questionIds.size()) {
        on_finishTestButton_clicked();
    } else {
        showQuestion(currentQuestionIndex);
    }

    // Очищаем поле ввода для следующего вопроса
    ui->answerInput->clear();
}

// Обработчик нажатия кнопки "Завершить тест"
void MainWindow::on_finishTestButton_clicked() {
    int userId = getUserIdByUsername(currentUserName);

    // Рассчитываем очки (10 очков за каждый правильный ответ)
    int score = correctAnswers * 10;
    // Обновляем очки пользователя с помощью метода updateUserExperience
    updateUserExperience(userId, score);

    // Обновляем количество выполненных тестов в таблице user_progress
    QSqlQuery progressQuery;
    progressQuery.prepare("UPDATE user_progress SET completed_tests_count = completed_tests_count + 1 WHERE user_id = ?");
    progressQuery.addBindValue(userId);

    if (!progressQuery.exec()) {
        qDebug() << "Ошибка обновления количества выполненных тестов:" << progressQuery.lastError().text();
    }

    // Сохраняем результат теста в таблице `test_results`
    QSqlQuery resultQuery;
    resultQuery.prepare("INSERT INTO test_results (user_id, test_id, score) VALUES (?, ?, ?)");
    resultQuery.addBindValue(userId);
    resultQuery.addBindValue(currentTestId);
    resultQuery.addBindValue(score);
    qDebug() << score << "очки";
    QMessageBox::information(this, "Успех", "Вы набрали " + QString::number(score) + " очков");

    if (!resultQuery.exec()) {
        qDebug() << "Ошибка сохранения результата теста:" << resultQuery.lastError().text();
    }

    // Сбрасываем состояние
    currentTestId = -1;
    currentQuestionIndex = 0;
    correctAnswers = 0;


    // Скрываем интерфейс теста
    ui->testframe->hide();
    ui->frame->show();
    ui->courseframe->hide();
}
int MainWindow::getUserIdByUsername(const QString &username) {
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
void MainWindow::fetchUserLevelAndExperience(int userId) {
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

void MainWindow::on_pushButton_2_clicked()
{

    ui->testframe->show();
    ui->frame->hide();
    ui->courseframe->hide();
    ui->upmenuTest->setStyleSheet("font: 700 14pt;");
    ui->upmenuHome->setStyleSheet("font: 14pt;");
}
void MainWindow::fetchCompletedCoursesAndLessons(int userId) {
    // Получение количества пройденных курсов
    QSqlQuery queryCourses;
    queryCourses.prepare("SELECT COUNT(DISTINCT course_id) AS completed_courses FROM user_progress WHERE user_id = ? AND is_completed = TRUE;");
    queryCourses.addBindValue(userId);

    if (queryCourses.exec() && queryCourses.next()) {
        int completedCourses = queryCourses.value(0).toInt();
        ui->completedCoursesLabel->setText("Пройденные курсы: " + QString::number(completedCourses));
    } else {
        qDebug() << "Ошибка получения количества пройденных курсов:" << queryCourses.lastError().text();
    }

    // Получение количества пройденных уроков
    QSqlQuery queryLessons;
    queryLessons.prepare("SELECT COUNT(DISTINCT lesson_id) AS completed_lessons FROM user_progress WHERE user_id = ? AND is_completed = TRUE;");
    queryLessons.addBindValue(userId);

    if (queryLessons.exec() && queryLessons.next()) {
        int completedLessons = queryLessons.value(0).toInt();
        ui->completedLessonsLabel->setText("Пройденные уроки: " + QString::number(completedLessons));
    } else {
        qDebug() << "Ошибка получения количества пройденных уроков:" << queryLessons.lastError().text();
    }
}
void MainWindow::on_pushButton_3_clicked()
{
    ui->courseframe->show();
    QSqlQuery query;
    query.prepare("SELECT id, title FROM courses");

    if (query.exec()) {
        while (query.next()) {
            int testId = query.value("id").toInt();
            QString testTitle = query.value("title").toString();

            ui->coursecomboBox->addItem(testTitle, testId);  // Добавляем тесты в ComboBox для выбора
        }
    } else {
        qDebug() << "Ошибка загрузки доступных курсов:" << query.lastError().text();
    }
}

void MainWindow::fetchCompletedTestsCount(int userId) {
    QSqlQuery query;
    query.prepare("SELECT completed_tests_count FROM user_progress WHERE user_id = ?");
    query.addBindValue(userId);

    if (query.exec() && query.next()) {
        int completedTests = query.value("completed_tests_count").toInt();
        ui->completedTestsLabel->setText("Пройденные тесты: " + QString::number(completedTests));
    } else {
        qDebug() << "Ошибка получения количества пройденных тестов:" << query.lastError().text();
    }
}

void MainWindow::on_pushButton_4_clicked()
{

    try {
          // Скрываем предыдущие виджеты или фреймы
        showFrameAtPosition();  // Используем метод для отображения фрейма
    } catch (const std::exception &e) {
        qDebug() << "Ошибка:" << e.what();  // Печатаем сообщение об ошибке
    } catch (...) {
        qDebug() << "Неизвестная ошибка";  // Печатаем сообщение о неизвестной ошибке
    }
}
void MainWindow::showFrameAtPosition() {

    ui->frame->hide();
    ui->testframe->hide();
    ui->courseframe->hide();
    frame = new MyFrame(this);


    // Задаём размер и положение фрейма
    frame->setGeometry(120, 90, 1681, 911);  // Позиция (100, 200), размер 300x200


    // Отображаем фрейм
    frame->show();
}

