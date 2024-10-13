#ifndef TESTFRAME_H
#define TESTFRAME_H

#include <QFrame>

namespace Ui {
class TestFrame;
}

class TestFrame : public QFrame
{
    Q_OBJECT

public:
    explicit TestFrame(const QString &username, QWidget *parent = nullptr);
    ~TestFrame();

private slots:
    void on_nextQuestionButton_clicked();

    void loadAvailableTests();

    void on_startTestButton_clicked();

    void loadTestQuestions();

    void showQuestion(int index);

    void on_finishTestButton_clicked();

    int getUserIdByUsername(const QString &username);

    void updateUserExperience(int userId, int pointsEarned);



private:
    Ui::TestFrame *ui;

    QString currentUserName;

    // Добавленные переменные для работы с тестами
    int currentTestId = -1;                // ID текущего теста
    int currentQuestionIndex = 0;          // Индекс текущего вопроса
    int correctAnswers = 0;                // Количество правильных ответов

    QVector<int> questionIds;              // Список ID вопросов текущего теста
    QVector<QString> questions;            // Список текстов вопросов
};

#endif // TESTFRAME_H
