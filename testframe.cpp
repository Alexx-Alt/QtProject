#include "testframe.h"
#include "ui_testframe.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QtCharts>



TestFrame::TestFrame(const QString &username, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::TestFrame), currentUserName(username)
{
    ui->setupUi(this);

    int userId = getUserIdByUsername(currentUserName);
    loadUserTestResults(userId);
    loadAvailableTests(userId);
}

TestFrame::~TestFrame()
{
    delete ui;
}
// Функция загрузки доступных тестов
void TestFrame::loadAvailableTests(int userId)
{
    QSqlQuery query;
    query.prepare("SELECT c.id, c.title "
                        "FROM lern.tests c "
                        "JOIN lern.user_tegs ut ON c.tegs_id = ut.tegs_id "
                        "WHERE ut.user_id = ? ");
    query.addBindValue(userId);

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
void TestFrame::on_startTestButton_clicked()
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
void TestFrame::loadTestQuestions()
{
    QSqlQuery query;
    query.prepare("SELECT id, question FROM test_questions WHERE test_id = ?");
    query.addBindValue(currentTestId);

    questionIds.clear();
    questions.clear();

    if (query.exec()) {
        while (query.next()) {
            int questionId = query.value("id").toInt();
            QString questionText = query.value("question").toString();

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
void TestFrame::showQuestion(int index)
{
    if (index < questions.size()) {
        ui->questionLabel->setText(questions[index]);
        ui->answerInput->clear();
        ui->nextQuestionButton->setEnabled(true);
        ui->finishTestButton->setEnabled(false);
    }
}

// Обработчик нажатия кнопки "Следующий вопрос"
void TestFrame::on_nextQuestionButton_clicked()
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
void TestFrame::on_finishTestButton_clicked() {

    int userId = getUserIdByUsername(currentUserName);

    // Рассчитываем очки (10 очков за каждый правильный ответ)
    int score = correctAnswers * 10;
    // Обновляем очки пользователя с помощью метода updateUserExperience
    updateUserExperience(userId, score);

    // Обновляем количество выполненных тестов в таблице user_progress
    if(score > 0){
        QSqlQuery progressQuery;
        progressQuery.prepare("UPDATE test_results SET test_count = test_count + 1 WHERE user_id = ?");
        progressQuery.addBindValue(userId);

        if (!progressQuery.exec()) {
            qDebug() << "Ошибка обновления количества выполненных тестов:" << progressQuery.lastError().text();
        }
    }
    // Сохраняем результат теста в таблице test_answers
    QSqlQuery resultQuery;
    resultQuery.prepare("INSERT INTO test_answers (user_id, test_id, score) VALUES (?, ?, ?)");
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
}
//функция получения id по имени
int TestFrame::getUserIdByUsername(const QString &username) {

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
//функция обновления уровня
void TestFrame::updateUserExperience(int userId, int pointsEarned) {
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
//функция вывода результатов теста
void TestFrame::loadUserTestResults(int userId) {

    QSqlQuery query;
    query.prepare("SELECT ta.completed_at, ta.score "
                  "FROM test_answers ta "
                  "WHERE ta.user_id = ? "
                  "ORDER BY ta.completed_at ASC");
    query.addBindValue(userId);

    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса на получение результатов тестов:" << query.lastError().text();
        return;
    }

    // Создаем серию для результатов
    QLineSeries *scoreSeries = new QLineSeries();
    // Создаем серию для дат
    QLineSeries *dateSeries = new QLineSeries();

    while (query.next()) {
        QDateTime completedAt = query.value(0).toDateTime(); // Получаем дату завершения
        int score = query.value(1).toInt(); // Получаем результат теста

        // Добавляем данные в серии
        scoreSeries->append(completedAt.toMSecsSinceEpoch(), score); // Используем дату как x-координату
        dateSeries->append(completedAt.toMSecsSinceEpoch(), score); // Можно также использовать для другого графика
    }

    // Создаем график
    QChart *chart = new QChart();
    chart->addSeries(scoreSeries);
    chart->createDefaultAxes();
    chart->setTitle("Результаты тестов по датам");

    // Настройка осей
    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTitleText("Дата завершения");
    axisX->setFormat("dd.MM.yyyy"); // Формат даты
    chart->setAxisX(axisX, scoreSeries); // Привязываем ось к серии результатов

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Результат");
    chart->setAxisY(axisY, scoreSeries); // Привязываем ось к серии результатов

    // Создаем QChartView и устанавливаем его геометрию
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Устанавливаем позицию и размеры графика
    chartView->setGeometry(970, 300, 561, 400); // X, Y, ширина, высота

    // Добавляем график к главному виджету
    chartView->setParent(this); // Убедитесь, что this - это ваш основной виджет
    chartView->show(); // Отображаем график
}
