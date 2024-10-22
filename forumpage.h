#ifndef FORUMPAGE_H
#define FORUMPAGE_H

#include <QFrame>
#include <QListWidgetItem>

namespace Ui {
class ForumPage;
}

class ForumPage : public QFrame
{
    Q_OBJECT

public:
    explicit ForumPage(const QString &username, QWidget *parent = nullptr);
    ~ForumPage();
private slots:
    void on_addQuestionButton_clicked(int userId);

    void on_addAnswerButton_clicked(int userId);


private:
    Ui::ForumPage *ui;

    QString currentUserName;

    int userId;

    int selectedQuestionId; // Переменная для хранения ID выбранного вопроса

    struct ForumQuestion {
        int id;
        int author_id;
        QString text;
        QString author_name;
        int parent_id;
    };

    int getUserIdByUsername(const QString &username);

    void loadForumQuestions();

    void displayForumQuestion(const ForumQuestion &question);

    void on_forumListWidget_itemClicked(QListWidgetItem *item); // Метод для обработки кликов по элементам

    void displaySelectedQuestion(int questionId);

    QString formatText(const QString &text);
};

#endif // FORUMPAGE_H
