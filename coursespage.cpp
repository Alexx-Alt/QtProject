#include "coursespage.h"
#include "ui_coursespage.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

CoursesPage::CoursesPage(const QString &username, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::CoursesPage)
    , currentUserName(username)
{
    ui->setupUi(this);

     connect(ui->coursesTable, &QTableWidget::cellClicked, this, &CoursesPage::onCourseSelected);
    int userId = getUserIdByUsername(currentUserName);
      loadCourses(userId);
}

CoursesPage::~CoursesPage()
{
    delete ui;
}
void CoursesPage::loadCourses(int userId)
{
    QSqlQuery query;
    query.prepare("SELECT c.id, c.title, c.description "
                        "FROM lern.courses c "
                         "JOIN lern.user_tegs ut ON c.tegs_id = ut.tegs_id "
                         "WHERE ut.user_id = ?  ");
    query.addBindValue(userId);

    if (!query.exec()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка загрузки курсов: " + query.lastError().text());
        return;
    }

    // Очищаем таблицу перед загрузкой
    ui->coursesTable->setRowCount(0);
    ui->coursesTable->setColumnCount(2); // Указываем 2 столбца для таблицы курсов
    ui->coursesTable->setHorizontalHeaderLabels(QStringList() << "Название курса" << "Описание курса");

    int row = 0;

    // Заполняем таблицу курсов
    while (query.next()) {
        int courseId = query.value(0).toInt();
        QString title = query.value(1).toString();
        QString description = query.value(2).toString();

        ui->coursesTable->insertRow(row);

        // Создаем элемент для названия курса
        QTableWidgetItem *titleItem = new QTableWidgetItem(title);
        titleItem->setData(Qt::UserRole, courseId);  // Сохраняем courseId в элементе
        ui->coursesTable->setItem(row, 0, titleItem);

        // Создаем элемент для описания курса
        ui->coursesTable->setItem(row, 1, new QTableWidgetItem(description));
        row++;
    }
    // Автоматическая подгонка столбцов под содержимое
    ui->coursesTable->resizeColumnsToContents();
    // Автоматическая подгонка строк под содержимое
    ui->coursesTable->resizeRowsToContents();
    // Автоматическая подгонка столбцов под содержимое
    ui->coursesTable->resizeColumnsToContents();
    // Автоматическая подгонка строк под содержимое
    ui->coursesTable->resizeRowsToContents();
}
void CoursesPage::loadLessons(int courseId)
{
    QSqlQuery query;
    query.prepare("SELECT title, content FROM lessons WHERE course_id = ?");
    query.addBindValue(courseId);

    if (!query.exec()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка загрузки уроков: " + query.lastError().text());
        return;
    }

    // Очищаем таблицу уроков
    ui->lessonsTable->setRowCount(0);
    ui->lessonsTable->setColumnCount(2); // Указываем 2 столбца для таблицы курсов
    ui->lessonsTable->setHorizontalHeaderLabels(QStringList() << "Название урока" << "Описание урока");
    int row = 0;

    // Заполняем таблицу уроков
    while (query.next()) {
        QString lessonTitle = query.value(0).toString();
        QString lessoncontent = query.value(1).toString();

        ui->lessonsTable->insertRow(row);
        ui->lessonsTable->setItem(row, 0, new QTableWidgetItem(lessonTitle));
        ui->lessonsTable->setItem(row, 1, new QTableWidgetItem(lessoncontent));
        row++;
    }
    // Автоматическая подгонка столбцов под содержимое
    ui->lessonsTable->resizeColumnsToContents();
    // Автоматическая подгонка строк под содержимое
    ui->lessonsTable->resizeRowsToContents();
    // Автоматическая подгонка столбцов под содержимое
    ui->lessonsTable->resizeColumnsToContents();
    // Автоматическая подгонка строк под содержимое
    ui->lessonsTable->resizeRowsToContents();
}

void CoursesPage::onCourseSelected(int row, int column)
{
    // Получаем ID курса из выбранной строки
    int courseId = ui->coursesTable->item(row, 0)->data(Qt::UserRole).toInt();

    // Загружаем уроки для выбранного курса
    loadLessons(courseId);
}

//функция получения Id пользователя по его username
int CoursesPage::getUserIdByUsername(const QString &username) {
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

