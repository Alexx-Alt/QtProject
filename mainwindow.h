#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &username, QWidget *parent = nullptr);
    ~MainWindow();
    // Добавьте здесь объявление метода updateUserExperience
    void updateUserExperience(int userId, int pointsEarned);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_startTestButton_clicked();

    void on_nextQuestionButton_clicked();

    void on_finishTestButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString currentUserName; // Переменная для хранения имени пользователя
    void fetchCompletedCoursesAndLessons(int userId);
    int getUserIdByUsername(const QString &username); //получения id по username
    void fetchUserLevelAndExperience(int userId); //получения уровня

    void loadAvailableTests();
    void loadTestQuestions();
    void showQuestion(int index);




    // Добавленные переменные для работы с тестами
    int currentTestId = -1;                // ID текущего теста
    int currentQuestionIndex = 0;          // Индекс текущего вопроса
    int correctAnswers = 0;                // Количество правильных ответов

    QVector<int> questionIds;              // Список ID вопросов текущего теста
    QVector<QString> questions;            // Список текстов вопросов


};
#endif // MAINWINDOW_H
