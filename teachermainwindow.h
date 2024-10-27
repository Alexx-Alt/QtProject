#ifndef TEACHERMAINWINDOW_H
#define TEACHERMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class TeacherMainWindow;
}

class TeacherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherMainWindow(QWidget *parent = nullptr);
    ~TeacherMainWindow();

private:
    Ui::TeacherMainWindow *ui;
};

#endif // TEACHERMAINWINDOW_H
