#include "uisetup.h"


UiSetup::UiSetup(Ui::MainWindow *ui)
    : ui(ui)
{
}
/**функция для настройки Ui*/
void UiSetup::setUpUi() {

    ui->widget->setFixedWidth(1);
    ui->widget_2->setFixedHeight(1);
    ui->widget->setStyleSheet("background-color: gray;");
    ui->widget_2->setStyleSheet("background-color: gray;");

    QPixmap main(":/img/house.png");
    QPixmap book(":/img/book.png");
    QPixmap course(":/img/course.png");

    ui->menulabel->setPixmap(main);
    ui->booklabel->setPixmap(book);
    ui->courselabel->setPixmap(course);

    ui->menulabel->setScaledContents(true);
    ui->booklabel->setScaledContents(true);
    ui->courselabel->setScaledContents(true);
}




void UiSetup::on_menutestbutton_clicked()
{

}

