#include "teachermainwindow.h"
#include "ui_teachermainwindow.h"
#include "studentprosmotr.h"
#include "login.h"

#include <QSettings>

TeacherMainWindow::TeacherMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TeacherMainWindow)
    , studentprosmotr(nullptr)
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

void TeacherMainWindow::on_studentbutton_clicked()
{
    showstudent();
}
void TeacherMainWindow::showstudent(){

    studentprosmotr = new StudentProsmotr(this);
    studentprosmotr->setGeometry(120, 90, 1681, 911);
    studentprosmotr->show();

}

void TeacherMainWindow::on_teacherbutton_clicked()
{
    // Удаляем токен и связанные данные из QSettings
    QSettings settings("MyApp", "MyAppName");
    settings.remove("userToken");
    settings.remove("username");
    settings.sync();

    // Закрываем текущее окно
    this->close();

    // Создаем новое окно входа
    login *loginWindow = new login();
    loginWindow->show();
}

