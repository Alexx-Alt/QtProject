#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QFrame>

namespace Ui {
class MainPage;
}

class MainPage : public QFrame
{
    Q_OBJECT

public:
    explicit MainPage(const QString &username, QWidget *parent = nullptr);
    ~MainPage();

private:
    Ui::MainPage *ui;

    QString currentUserName;

    void fetchUserLevelAndExperience(int userId);

    int getUserIdByUsername(const QString &username);

    void fetchCompletedCoursesAndLessons(int userId);

    void fetchCompletedTestsCount(int userId);

    void updateUserExperience(int userId);
};

#endif // MAINPAGE_H
