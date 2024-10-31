#include "teasherstudentframe.h"
#include "ui_teasherstudentframe.h"

TeasherStudentFrame::TeasherStudentFrame(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::TeasherStudentFrame)
{
    ui->setupUi(this);
}

TeasherStudentFrame::~TeasherStudentFrame()
{
    delete ui;
}

