#include "myframe.h"
#include "ui_myframe.h"

MyFrame::MyFrame(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::MyFrame)
{
    ui->setupUi(this);
}

MyFrame::~MyFrame()
{
    delete ui;
}
