#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QSplitter>
#include <QGridLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setFixedSize(1800, 1000); // Установите фиксированный размер окна

    // QWidget *centralWidget = new QWidget(this);

    // QVBoxLayout *layout = new QVBoxLayout(centralWidget);


   //  // Устанавливаем политику размеров
   //  QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
   //  ui->menuwidget->setSizePolicy(sizePolicy);
   // ui->pushButton->setFixedSize(100,100);
    //ui->menuwidget->setFixedWidth(100);

    // Добавляем виджет в компоновщик
    // layout->addWidget(ui->menuwidget);
    // layout->addWidget(ui->pushButton);
    // Пример анимации
    // В вашем основном окне
    // Создаем анимацию для изменения высоты меню
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(ui->menuwidget);
    QPixmap pixmap(":/img/menu.png");
    QPixmap menuactive(":/img/menuactive.png");
    ui->menulabel->setPixmap(pixmap);
    ui->menulabel->setScaledContents(true);




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
     QMessageBox::warning(this, "Ошибка", "dddddddddddd.");
    QPixmap menuactive(":/img/menuactive.png");
     ui->menulabel->setPixmap(menuactive);

}

