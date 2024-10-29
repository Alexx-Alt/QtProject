#ifndef TEACHERMAINWINDOW_H
#define TEACHERMAINWINDOW_H

#include <QMainWindow>
#include "studentprosmotr.h"

namespace Ui {
class TeacherMainWindow;
}

class TeacherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherMainWindow(QWidget *parent = nullptr);
    ~TeacherMainWindow();

private slots:
    void on_studentbutton_clicked();

private:
    Ui::TeacherMainWindow *ui;
    StudentProsmotr *studentprosmotr;
    void showstudent();
};

#endif // TEACHERMAINWINDOW_H
