#include "forumpage.h"
#include "ui_forumpage.h"
#include "userprofiledialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QDebug>

ForumPage::ForumPage(const QString &username, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::ForumPage)
    , currentUserName(username)
    , selectedQuestionId(-1)  // Изначально никакой вопрос не выбран
{
    ui->setupUi(this);
    int userId = getUserIdByUsername(currentUserName);
    // Подключаем сигнал клика по элементу списка к слоту
    connect(ui->forumListWidget, &QListWidget::itemClicked, this, &ForumPage::on_forumListWidget_itemClicked);
    loadForumQuestions();

    connect(ui->addAnswerButton, &QPushButton::clicked, this, [this, userId]() {
        on_addAnswerButton_clicked(userId);  // Вызов слота с передачей userId
    });
    connect(ui->addQuestionButton, &QPushButton::clicked, this, [this, userId]() {
        on_addQuestionButton_clicked(userId);  // Вызов слота с передачей userId
    });
    ui->selectedQuestionTextEdit->setReadOnly(true);

}

ForumPage::~ForumPage()
{
    delete ui;
}
//функция получения id по username
int ForumPage::getUserIdByUsername(const QString &username) {
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
// Пример структуры для хранения вопросов
struct ForumQuestion {
    int id;
    int author_id;
    QString text;
    QString author_name;
    int parent_id;
};
// Обработка клика по элементу списка
void ForumPage::on_forumListWidget_itemClicked(QListWidgetItem *item) {
    int questionId = item->data(Qt::UserRole).toInt();
    selectedQuestionId = questionId;  // Обновляем выбранный ID вопроса
    displaySelectedQuestion(questionId);
}
// Функция загрузки вопросов и ответов
void ForumPage::loadForumQuestions() {
    QSqlQuery query;
    // Извлекаем id, имя автора, текст и parent_id
    query.prepare("SELECT fq.id, fq.author_id, u.username, fq.text, fq.parent_id "
                  "FROM forum_question fq "
                  "JOIN users u ON fq.author_id = u.id");

    if (query.exec()) {
        while (query.next()) {
            ForumQuestion question;
            question.id = query.value(0).toInt();
            question.author_id = query.value(1).toInt();
            question.author_name = query.value(2).toString();  // Получаем имя автора
            question.text = query.value(3).toString();
            question.parent_id = query.value(4).toInt();

            // Отображаем вопрос в интерфейсе
            displayForumQuestion(question);
        }
    } else {
        qDebug() << "Ошибка загрузки вопросов:" << query.lastError().text();
    }
}
void ForumPage::displayForumQuestion(const ForumQuestion &question) {
    QListWidgetItem *item = new QListWidgetItem;

    if (question.parent_id == 0) {
        item->setText("Вопрос: " + question.text + "\nАвтор: " + question.author_name);
    } else {
        item->setText("  Ответ: " + question.text + "\nАвтор: " + question.author_name);
        item->setBackground(Qt::white);
    }

    item->setData(Qt::UserRole, question.id);              // ID вопроса
    item->setData(Qt::UserRole + 1, question.author_name); // Имя автора

    ui->forumListWidget->addItem(item);
}
// Добавление нового вопроса
void ForumPage::on_addQuestionButton_clicked(int userId) {
    QString questionText = ui->newQuestionTextEdit->toPlainText();

    if (!questionText.isEmpty()) {
        QSqlQuery query;
        query.prepare("INSERT INTO forum_question (author_id, text, parent_id) VALUES (:author_id, :text, :parent_id)");
        query.bindValue(":author_id", userId);
        query.bindValue(":text", questionText);
        query.bindValue(":parent_id", 0);  // Новый вопрос, parent_id = 0

        if (query.exec()) {
            ForumQuestion newQuestion;
            newQuestion.id = query.lastInsertId().toInt();
            newQuestion.author_id = userId;
            newQuestion.author_name = currentUserName;  // Используем уже известное имя автора
            newQuestion.text = questionText;
            newQuestion.parent_id = 0;

            // Обновляем интерфейс
            displayForumQuestion(newQuestion);
        } else {
            qDebug() << "Ошибка добавления вопроса:" << query.lastError().text();
        }
    }
}
// Добавление нового ответа
void ForumPage::on_addAnswerButton_clicked(int userId) {
    QString answerText = ui->newAnswerTextEdit->toPlainText();
    int parentId = selectedQuestionId;  // ID выбранного вопроса

    if (!answerText.isEmpty() && parentId != -1) {
        QSqlQuery query;
        query.prepare("INSERT INTO forum_question (author_id, text, parent_id) VALUES (:author_id, :text, :parent_id)");
        query.bindValue(":author_id", userId);
        query.bindValue(":text", answerText);
        query.bindValue(":parent_id", parentId);  // Это ответ, parent_id не равен 0

        if (query.exec()) {
            ForumQuestion newAnswer;
            newAnswer.id = query.lastInsertId().toInt();
            newAnswer.author_id = userId;
            newAnswer.author_name = currentUserName;  // Используем уже известное имя автора
            newAnswer.text = answerText;
            newAnswer.parent_id = parentId;

            // Обновляем интерфейс
            displayForumQuestion(newAnswer);
        } else {
            qDebug() << "Ошибка добавления ответа:" << query.lastError().text();
        }
    }
}
void ForumPage::displaySelectedQuestion(int questionId) {
    QString displayText;  // Строка для формирования полного текста
    QSqlQuery query;

    // Сначала получаем информацию о вопросе
    query.prepare("SELECT fq.text, u.username, fq.parent_id "
                  "FROM forum_question fq "
                  "JOIN users u ON fq.author_id = u.id "
                  "WHERE fq.id = ?");
    query.addBindValue(questionId);

    if (query.exec() && query.next()) {
        int parentId = query.value(2).toInt();

        if (parentId == 0) {  // Если это вопрос
            QString questionText = query.value(0).toString();
            QString authorName = query.value(1).toString();

            // Форматируем и добавляем вопрос
            QString formattedQuestion = formatText(questionText);
            displayText += "<h3>Вопрос от <b>" + authorName + "</b>:</h3>";
            displayText += formattedQuestion;
            displayText += "<br><br>";
            displayText += "<h3>Ответы:</h3>";

            // Получаем все ответы на этот вопрос
            QSqlQuery answersQuery;
            answersQuery.prepare("SELECT fq.text, u.username "
                                 "FROM forum_question fq "
                                 "JOIN users u ON fq.author_id = u.id "
                                 "WHERE fq.parent_id = ? "
                                 "ORDER BY fq.id");  // Сортировка по ID для хронологического порядка
            answersQuery.addBindValue(questionId);

            if (answersQuery.exec()) {
                while (answersQuery.next()) {
                    QString answerText = answersQuery.value(0).toString();
                    QString answerAuthor = answersQuery.value(1).toString();

                    // Форматируем и добавляем каждый ответ
                    QString formattedAnswer = formatText(answerText);
                    displayText += "<div style='margin-left: 20px; margin-bottom: 10px;'>";
                    displayText += "<b>" + answerAuthor + "</b> ответил:<br>";
                    displayText += formattedAnswer;
                    displayText += "</div>";
                }
            }
        } else {  // Если это ответ, получаем родительский вопрос
            // Получаем информацию о родительском вопросе
            QSqlQuery parentQuery;
            parentQuery.prepare("SELECT fq.text, u.username "
                                "FROM forum_question fq "
                                "JOIN users u ON fq.author_id = u.id "
                                "WHERE fq.id = ?");
            parentQuery.addBindValue(parentId);

            if (parentQuery.exec() && parentQuery.next()) {
                QString questionText = parentQuery.value(0).toString();
                QString questionAuthor = parentQuery.value(1).toString();

                // Форматируем и добавляем вопрос
                QString formattedQuestion = formatText(questionText);
                displayText += "<h3>Вопрос от <b>" + questionAuthor + "</b>:</h3>";
                displayText += formattedQuestion;
                displayText += "<br><br>";
                displayText += "<h3>Ответы:</h3>";

                // Получаем все ответы на этот вопрос
                QSqlQuery answersQuery;
                answersQuery.prepare("SELECT fq.text, u.username "
                                     "FROM forum_question fq "
                                     "JOIN users u ON fq.author_id = u.id "
                                     "WHERE fq.parent_id = ? "
                                     "ORDER BY fq.id");  // Сортировка по ID для хронологического порядка
                answersQuery.addBindValue(parentId);

                if (answersQuery.exec()) {
                    while (answersQuery.next()) {
                        QString answerText = answersQuery.value(0).toString();
                        QString answerAuthor = answersQuery.value(1).toString();

                        // Форматируем и добавляем каждый ответ
                        QString formattedAnswer = formatText(answerText);
                        displayText += "<div style='margin-left: 20px; margin-bottom: 10px;'>";
                        displayText += "<b>" + answerAuthor + "</b> ответил:<br>";
                        displayText += formattedAnswer;
                        displayText += "</div>";
                    }
                }
            }
        }
    }

    // Выводим полный текст в TextEdit
    ui->selectedQuestionTextEdit->setHtml(displayText);
}
void ForumPage::loadAnswers(int questionId) {
    QSqlQuery query;
    query.prepare("SELECT fq.text, u.username "
                  "FROM forum_question fq "
                  "JOIN users u ON fq.author_id = u.id "
                  "WHERE fq.parent_id = ?");
    query.addBindValue(questionId);

    ui->answersListWidget->clear();
    if (query.exec()) {
        while (query.next()) {
            QString answerText = query.value(0).toString();
            QString answerAuthor = query.value(1).toString();

            // Применяем форматирование к тексту ответа
            QString formattedAnswer = formatText(answerText);

            // Создаем и настраиваем элемент списка
            QListWidgetItem* item = new QListWidgetItem;
            item->setText("Ответ от " + answerAuthor + ":\n" + answerText);

            // Можно добавить визуальное оформление для ответов
            item->setBackground(Qt::white);

            // Добавляем элемент в список ответов
            ui->answersListWidget->addItem(item);
        }
    } else {
        qDebug() << "Ошибка загрузки ответов:" << query.lastError().text();
    }
}
QString ForumPage::formatText(const QString &text) {
    QString formattedText = text;

    // Жирный текст (**текст**)
    QRegularExpression boldRegex("\\*\\*(.*?)\\*\\*");
    formattedText.replace(boldRegex, "<b>\\1</b>");

    // Курсив (*текст*)
    QRegularExpression italicRegex("\\*(.*?)\\*");
    formattedText.replace(italicRegex, "<i>\\1</i>");

    // Подчеркнутый текст (__текст__)
    QRegularExpression underlineRegex("__(.*?)__");
    formattedText.replace(underlineRegex, "<u>\\1</u>");

    // Зачеркнутый текст (~~текст~~)
    QRegularExpression strikeRegex("~~(.*?)~~");
    formattedText.replace(strikeRegex, "<s>\\1</s>");

    // Замена переносов строк на HTML-переносы
    formattedText.replace("\n", "<br>");

    return formattedText;
}

void ForumPage::on_showUserProfile_clicked()
{

    QListWidgetItem *selectedItem = ui->forumListWidget->currentItem();
    QString name = selectedItem->data(Qt::UserRole + 1).toString();
    QSqlQuery query;

    // Получение email пользователя
    query.prepare("SELECT email FROM users WHERE username = ?");
    query.addBindValue(name);
    QString email;
    if (query.exec() && query.next()) {
        email = query.value(0).toString();
    } else {
        qDebug() << "Ошибка загрузки профиля:" << query.lastError().text();
        return;
    }

    QSqlQuery queryCourses;
    queryCourses.prepare("SELECT COUNT(DISTINCT course_id) AS completed_courses FROM user_progress WHERE user_id = (SELECT id FROM users WHERE username = ?) AND completed = TRUE;");
    queryCourses.addBindValue(name);
    int completedCourses = 0;
    if (queryCourses.exec() && queryCourses.next()) {
        completedCourses = queryCourses.value(0).toInt();

    } else {
        qDebug() << "Ошибка получения количества пройденных курсов:" << queryCourses.lastError().text();
    }

    // Получение количества пройденных уроков
    QSqlQuery queryLessons;
    queryLessons.prepare("SELECT COUNT(DISTINCT lesson_id) AS completed_lessons FROM user_progress WHERE user_id = (SELECT id FROM users WHERE username = ?) AND completed = TRUE;");
    queryLessons.addBindValue(name);
    int completedLessons = 0;
    if (queryLessons.exec() && queryLessons.next()) {
        completedLessons = queryLessons.value(0).toInt();

    } else {
        qDebug() << "Ошибка получения количества пройденных уроков:" << queryLessons.lastError().text();
    }

    // Получение количества пройденных тестов
    QSqlQuery testquery;
    testquery.prepare("SELECT test_count FROM test_results WHERE user_id = (SELECT id FROM users WHERE username = ?)");
    testquery.addBindValue(name);
    int completedTests = 0;
    if (testquery.exec() && testquery.next()) {
        completedTests = testquery.value(0).toInt();

    } else {
        qDebug() << "Ошибка получения количества пройденных тестов:" << query.lastError().text();
    }

    // Отображение профиля в новом окне
    UserProfileDialog profileDialog(this);
    profileDialog.setProfileInfo(name, email, completedCourses, completedLessons, completedTests);
    profileDialog.exec();
}

