#ifndef COURSESPAGE_H
#define COURSESPAGE_H

#include <QFrame>
#include <QSqlQuery>
#include <QTableWidget>

namespace Ui {
class CoursesPage;
}

class CoursesPage : public QFrame
{
    Q_OBJECT

public:
    explicit CoursesPage(const QString &username, QWidget *parent = nullptr);
    ~CoursesPage();

private:
    Ui::CoursesPage *ui;

    QString currentUserName;
    

    void loadCourses(int userId);  // Загрузка курсов
    void loadLessons(int courseId);  // Загрузка уроков по выбранному курсу

    int getUserIdByUsername(const QString &username);



private slots:
    void onCourseSelected(int row); // Обработка клика по курсу

    void onLessonSelected(int row);
    QString formatText(const QString &text);

    void markLessonAsCompleted(int lessonId, int courseId);

    void on_completeLessonButton_clicked();
};

#endif // COURSESPAGE_H
