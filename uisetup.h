#ifndef UISETUP_H
#define UISETUP_H

#include <QWidget>
#include "ui_mainwindow.h"
#include "mainpage.h"

class UiSetup {
public:
    explicit UiSetup(Ui::MainWindow *ui);

    void setUpUi();

    void showFrameAtPosition();




private slots:
    void on_maimpagebutton_clicked();

    void on_menutestbutton_clicked();

private:
    Ui::MainWindow *ui;
    MainPage *mainpage;
};

#endif // UISETUP_H
