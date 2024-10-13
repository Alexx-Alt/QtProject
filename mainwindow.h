#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainpage.h"
#include "uisetup.h"
#include "testframe.h"

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

    void hideallframe();

    void allfont();

    void showtestpage();




private:
    Ui::MainWindow *ui;
    QString currentUserName; // Переменная для хранения имени пользователя
    MainPage *mainpage;
    TestFrame *testpage;
    UiSetup uiSetup;
};
#endif // MAINWINDOW_H
