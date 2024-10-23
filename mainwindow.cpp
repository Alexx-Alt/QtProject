#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uisetup.h"
#include "mainpage.h"
#include "testframe.h"
#include "login.h"

#include <QSettings>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QFile>
#include <QObject>
#include <QFileDialog>
#include <QFile>
#include <QSqlError>

MainWindow::MainWindow(const QString &username, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), currentUserName(username), mainpage(nullptr), testpage(nullptr), uiSetup(ui), profile(nullptr), coursepage(nullptr), forumpage(nullptr), manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    //размер окна
    setFixedSize(1800, 1000);

    uiSetup.setUpUi();
    QString username2 = username;
    int userId = getUserIdByUsername(currentUserName);
    avatr(userId);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logoutButton_clicked()
{
    // Удаляем токен и связанные данные из QSettings
    QSettings settings("MyApp", "MyAppName");
    settings.remove("userToken");
    settings.remove("username");
    settings.sync();

    // Показываем сообщение об успешном выходе
    QMessageBox::information(this, "Выход", "Вы успешно вышли из системы.");

    // Закрываем текущее окно и открываем окно входа
    this->close();
    login *loginWindow = new login();
    loginWindow->show();
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

void MainWindow::avatr(int userId){

    // Получение пути к аватарке из базы данных
    QSqlQuery query;
    query.prepare("SELECT pathtoavatr FROM avatars WHERE user_id = :userId");
    query.bindValue(":userId", userId);

    if (query.exec() && query.next()) {
        QString avatarPath = query.value(0).toString();



        // Создание запроса
        QNetworkRequest request(avatarPath);
        QNetworkReply* reply = manager->get(request);
        // Обрабатываем завершение запроса
        connect(reply, &QNetworkReply::finished, [reply, this]() {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray avatarData = reply->readAll();
                QPixmap pixmap;
                pixmap.loadFromData(avatarData); // Загружаем изображение из данных

                // Устанавливаем QPixmap в QLabel
                ui->avatarLabel->setPixmap(pixmap.scaled(ui->avatarLabel->size(), Qt::KeepAspectRatio)); // Масштабируем изображение
                qDebug() << "Avatar downloaded and displayed.";
            } else {
                qDebug() << "Error downloading avatar:" << reply->errorString();
            }
            reply->deleteLater(); // Освобождаем reply
        });
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось найти аватарку для пользователя.");
    }

}
int MainWindow::getUserIdByUsername(const QString &username) {
    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE username = ?"); // Предполагается, что имя пользователя хранится в поле username
    query.addBindValue(username);

    if (query.exec() && query.next()) {
        return query.value(0).toInt(); // Возвращаем ID пользователя
    } else {
        qDebug() << "Ошибка получения ID пользователя:" << query.lastError().text();
        return -1; // Возвращаем -1 в случае ошибки или если пользователь не найден
    }
}
