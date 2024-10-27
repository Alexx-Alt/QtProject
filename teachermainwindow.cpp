#include "teachermainwindow.h"
#include "ui_teachermainwindow.h"

TeacherMainWindow::TeacherMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TeacherMainWindow)
{
    ui->setupUi(this);
    ui->widget->setFixedWidth(1);
    ui->widget_2->setFixedHeight(1);
    ui->widget->setStyleSheet("background-color: gray;");
    ui->widget_2->setStyleSheet("background-color: gray;");
}

TeacherMainWindow::~TeacherMainWindow()
{
    delete ui;
}
