#ifndef COURSETEACHER_H
#define COURSETEACHER_H

#include <QFrame>

namespace Ui {
class CourseTeacher;
}

class CourseTeacher : public QFrame
{
    Q_OBJECT

public:
    explicit CourseTeacher(QWidget *parent = nullptr);
    ~CourseTeacher();

private:
    Ui::CourseTeacher *ui;
};

#endif // COURSETEACHER_H
