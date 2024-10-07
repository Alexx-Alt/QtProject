#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QSplitter>
#include <QGridLayout>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(const QString &username, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), currentUserName(username)
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


    QPixmap pixmap(":/img/house.png");
    QPixmap book(":/img/book.png");
    ui->frame->hide();

    ui->menulabel->setPixmap(pixmap);
    ui->booklabel->setPixmap(book);
    ui->menulabel->setScaledContents(true);
    ui->booklabel->setScaledContents(true);
    ui->widget->setFixedWidth(1);                                   // Устанавливаем фиксированную ширину
    ui->widget_2->setFixedHeight(1);                                   // Устанавливаем фиксированную ширину
    ui->widget->setStyleSheet("background-color: gray;");           // Устанавливаем цвет линии
    ui->widget_2->setStyleSheet("background-color: gray;");           // Устанавливаем цвет линии
    // Заголовок
    ui->welcomeLabel->setText("Добро пожаловать, " + currentUserName + "!");
    // Получите ID пользователя (предполагаем, что у вас есть метод для этого)
    int userId = getUserIdByUsername(currentUserName);

    if (userId != -1) {
        // Получаем пройденные курсы и уроки
        fetchCompletedCoursesAndLessons(userId);
        fetchUserLevelAndExperience(userId);  // Получаем его уровень и очки опыта
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось найти пользователя.");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

    ui->frame->show();
    ui->upmenuHome->setStyleSheet("font: 700 14pt;");



}
void MainWindow::fetchCompletedCoursesAndLessons(int userId) {
    // Получение количества пройденных курсов
    QSqlQuery queryCourses;
    queryCourses.prepare("SELECT COUNT(DISTINCT course_id) AS completed_courses FROM user_progress WHERE user_id = ? AND is_completed = TRUE;");
    queryCourses.addBindValue(userId);

    if (queryCourses.exec() && queryCourses.next()) {
        int completedCourses = queryCourses.value(0).toInt();
        ui->completedCoursesLabel->setText("Пройденные курсы: " + QString::number(completedCourses));
    } else {
        qDebug() << "Ошибка получения количества пройденных курсов:" << queryCourses.lastError().text();
    }

    // Получение количества пройденных уроков
    QSqlQuery queryLessons;
    queryLessons.prepare("SELECT COUNT(DISTINCT lesson_id) AS completed_lessons FROM user_progress WHERE user_id = ? AND is_completed = TRUE;");
    queryLessons.addBindValue(userId);

    if (queryLessons.exec() && queryLessons.next()) {
        int completedLessons = queryLessons.value(0).toInt();
        ui->completedLessonsLabel->setText("Пройденные уроки: " + QString::number(completedLessons));
    } else {
        qDebug() << "Ошибка получения количества пройденных уроков:" << queryLessons.lastError().text();
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
void MainWindow::fetchUserLevelAndExperience(int userId) {
    QSqlQuery query;
    query.prepare("SELECT level, experience_points FROM users WHERE id = ?");
    query.addBindValue(userId);

    if (query.exec() && query.next()) {
        int level = query.value("level").toInt();
        int experiencePoints = query.value("experience_points").toInt();

        // Отображение на главной странице
        ui->welcomeLabel->setText("Добро пожаловать, " + currentUserName + "! Текущий уровень: " + QString::number(level));
        ui->experienceLabel->setText("Очки опыта: " + QString::number(experiencePoints));
    } else {
        qDebug() << "Ошибка получения уровня и очков опыта:" << query.lastError().text();
    }
}

