#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uisetup.h"
#include "mainpage.h"
#include "testframe.h"

MainWindow::MainWindow(const QString &username, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), currentUserName(username), mainpage(nullptr), testpage(nullptr), uiSetup(ui), profile(nullptr), coursepage(nullptr), forumpage(nullptr)
{
    ui->setupUi(this);
    //размер окна
    setFixedSize(1800, 1000);

    uiSetup.setUpUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    hideallframe();
    allfont();
}
//кнопка показа главного меню
void MainWindow::on_maimpagebutton_clicked()
{
    allfont();
    showFrameAtPosition();

    ui->upmenuHome->setStyleSheet("font: 700 14pt;");
}
//кнопка показа окна с тестами
void MainWindow::on_menutestbutton_clicked()
{
    hideallframe();
    allfont();
    showtestpage();

    ui->upmenuTest->setStyleSheet("font: 700 14pt;");
}
void MainWindow::on_ProfileButton_clicked()
{
    hideallframe();
    allfont();
    showprofile();
}
void MainWindow::on_menucoursebutton_clicked()
{
    hideallframe();
    allfont();
    showcourse();
}
void MainWindow::on_forumbutton_clicked()
{
    hideallframe();
    allfont();
    showforum();
}
//функция чтоб скрыть все фреймы
void MainWindow::hideallframe()
{
    if (mainpage) {
        delete mainpage;
        mainpage = nullptr;
    }
    if (testpage) {
        delete testpage;
        testpage = nullptr;
    }
    if (profile) {
        delete profile;
        profile = nullptr;
    }
    if (coursepage) {
        delete coursepage;
        coursepage = nullptr;
    }
    if (forumpage) {
        delete forumpage;
        forumpage = nullptr;
    }
}
//функция чтоб убрать выделение со всез лейблов верхенего дублирования меню
void MainWindow::allfont()
{
    ui->upmenuTest->setStyleSheet("font: 14pt;");
    ui->upmenuHome->setStyleSheet("font: 14pt;");
}
//функция показа главной страницы
void MainWindow::showFrameAtPosition()
{
    mainpage = new MainPage(currentUserName, this);
    mainpage->setGeometry(120, 90, 1681, 911);
    mainpage->show();
}
//функция показа страницы c тестами
void MainWindow::showtestpage()
{
    testpage = new TestFrame(currentUserName, this);
    testpage->setGeometry(120, 90, 1681, 911);
    testpage->show();
}
void MainWindow::showprofile(){

    profile = new Profile(currentUserName, this);
    profile->setGeometry(120, 90, 1681, 911);
    profile->show();

}
void MainWindow::showcourse(){

    coursepage = new CoursesPage(currentUserName, this);
    coursepage->setGeometry(120, 90, 1681, 911);
    coursepage->show();

}
void MainWindow::showforum(){

    forumpage = new ForumPage(currentUserName, this);
    forumpage->setGeometry(120, 90, 1681, 911);
    forumpage->show();

}

