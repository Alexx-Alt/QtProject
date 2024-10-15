#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainpage.h"
#include "uisetup.h"
#include "testframe.h"
#include "profile.h"

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
    void on_pushButton_4_clicked();

    void showFrameAtPosition();

    void on_maimpagebutton_clicked();

    void on_menutestbutton_clicked();

    void on_ProfileButton_clicked();

    void hideallframe();

    void allfont();

    void showtestpage();

    void showprofile();




private:
    Ui::MainWindow *ui;
    QString currentUserName; // Переменная для хранения имени пользователя
    MainPage *mainpage;
    TestFrame *testpage;
    UiSetup uiSetup;
    Profile *profile;
};
#endif // MAINWINDOW_H
