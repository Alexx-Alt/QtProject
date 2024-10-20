#include "forumpage.h"
#include "ui_forumpage.h"

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
    QString itemText = item->text();

    // Пример: нужно извлечь ID вопроса из текста или данных элемента
    // Здесь предполагается, что текст элемента в формате: "Вопрос: [текст] (ID: [номер])"
    int idStart = itemText.indexOf("(ID: ") + 5;
    int idEnd = itemText.indexOf(")", idStart);
    selectedQuestionId = itemText.mid(idStart, idEnd - idStart).toInt();

    qDebug() << "Выбран вопрос с ID:" << selectedQuestionId;
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
        // Основной вопрос
        item->setText("Вопрос: " + question.text + "\nАвтор: " + question.author_name + " (ID: " + QString::number(question.id) + ")");

    } else {
        // Ответ на вопрос
        item->setText("  Ответ: " + question.text + "\nАвтор: " + question.author_name + " (ID: " + QString::number(question.id) + ")");  // С отступом
        // Отображаем с небольшим отступом, чтобы визуально отличить ответы
        item->setBackground(Qt::white);
    }

    // Добавляем элемент в список вопросов
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



