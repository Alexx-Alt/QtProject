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

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString currentUserName; // Переменная для хранения имени пользователя
    void fetchCompletedCoursesAndLessons(int userId);
    int getUserIdByUsername(const QString &username); //получения id по username
    void fetchUserLevelAndExperience(int userId); //получения уровня

};
#endif // MAINWINDOW_H
