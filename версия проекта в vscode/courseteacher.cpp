#include "courseteacher.h"
#include "ui_courseteacher.h"

CourseTeacher::CourseTeacher(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::CourseTeacher)
{
    ui->setupUi(this);
}

CourseTeacher::~CourseTeacher()
{
    delete ui;
}
