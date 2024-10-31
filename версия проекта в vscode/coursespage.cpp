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
    connect(ui->lessonsTable, &QTableWidget::cellClicked, this, &CoursesPage::onLessonSelected);
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
                  "WHERE ut.user_id = ? ");
    query.addBindValue(userId);

    if (!query.exec()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка загрузки курсов: " + query.lastError().text());
        return;
    }

    // Clear the table before loading new data
    ui->coursesTable->setRowCount(0);
    ui->coursesTable->setColumnCount(2); // Set 2 columns for the courses table
    ui->coursesTable->setHorizontalHeaderLabels(QStringList() << "Название курса" << "Описание курса");

    int currentRow = 0;

    // Populate the courses table
    while (query.next()) {
        int courseId = query.value(0).toInt();
        QString courseTitle = query.value(1).toString();
        QString courseDescription = query.value(2).toString();
        
        ui->coursesTable->insertRow(currentRow);

        // Create an item for the course title
        QTableWidgetItem *titleItem = new QTableWidgetItem(courseTitle);
        titleItem->setData(Qt::UserRole, courseId); // Store courseId in the item
        ui->coursesTable->setItem(currentRow, 0, titleItem);

        // Create an item for the course description
        ui->coursesTable->setItem(currentRow, 1, new QTableWidgetItem(courseDescription));
        currentRow++;
    }

    // Adjust columns and rows to fit contents
    ui->coursesTable->resizeColumnsToContents();
    ui->coursesTable->resizeRowsToContents();
}
void CoursesPage::loadLessons(int courseId)
{
    QSqlQuery query;
    // Выбираем также ID урока
    query.prepare("SELECT id, title, content FROM lessons WHERE course_id = ?");
    query.addBindValue(courseId);

    if (!query.exec()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка загрузки уроков: " + query.lastError().text());
        return;
    }

    // Очищаем таблицу уроков
    ui->lessonsTable->setRowCount(0);
    ui->lessonsTable->setColumnCount(2); // Указываем 2 столбца для таблицы уроков
    ui->lessonsTable->setHorizontalHeaderLabels(QStringList() << "Название урока" << "Описание урока");

    int row = 0;

    // Заполняем таблицу уроков
    while (query.next()) {
        int lessonId = query.value(0).toInt();  // Получаем ID урока
        QString lessonTitle = query.value(1).toString();
        QString lessonContent = query.value(2).toString();

        ui->lessonsTable->insertRow(row);

        // Создаем элемент для названия урока и сохраняем в нем ID урока
        QTableWidgetItem *titleItem = new QTableWidgetItem(lessonTitle);
        titleItem->setData(Qt::UserRole, lessonId);  // Сохраняем ID урока в элементе
        ui->lessonsTable->setItem(row, 0, titleItem);

        // Добавляем описание урока
        ui->lessonsTable->setItem(row, 1, new QTableWidgetItem(lessonContent));

        row++;
    }

    // Автоматическая подгонка столбцов под содержимое
    ui->lessonsTable->resizeColumnsToContents();
    ui->lessonsTable->resizeRowsToContents();
}

void CoursesPage::onCourseSelected(int row)
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
void CoursesPage::onLessonSelected(int row)
{
    ui->lessontextedit->setReadOnly(true);
     QString displayText;
    // Получаем ID урока из выбранной строки
    int lessonId = ui->lessonsTable->item(row, 0)->data(Qt::UserRole).toInt();

    qDebug() << "Выбранный урок ID:" << lessonId;
    QSqlQuery query;
    // Выбираем также ID урока
    query.prepare("SELECT title, contentles FROM lessons WHERE id = ?");
    query.addBindValue(lessonId);
    if(query.exec()){
        while (query.next()){
        QString title = query.value(0).toString();
        QString lessonText = query.value(1).toString();
        // Предположим, что у вас есть путь к изображению, который вы хотите вставить
        QString imagePath = ":/img/house.png"; // Замените на реальный путь к изображению


        QString formattedLesson = formatText(lessonText);
        displayText += "урок: <b>" + title + "</b>" + "<br>";
        displayText += formattedLesson;
        ui->lessontextedit->setHtml(displayText);
        }
    }
    else{
        qDebug() << "ошибка" << query.lastError();
    }

}
//функция форматирования текста
QString CoursesPage::formatText(const QString &text) {
    QString formattedText = text;
    

    // Жирный текст (**текст**)
    QRegularExpression boldRegex("\\*\\*(.*?)\\*\\*");
    formattedText.replace(boldRegex, "<b>\\1</b>");

    // Курсив (*текст*)
    QRegularExpression italicRegex("\\*(.*?)\\*");
    formattedText.replace(italicRegex, "<i>\\1</i>");

    // Подчеркнутый текст (__текст__)
    QRegularExpression underlineRegex("__(.*?)__");
    formattedText.replace(underlineRegex, "<u>\\1</u>");

    // Зачеркнутый текст (~~текст~~)
    QRegularExpression strikeRegex("~~(.*?)~~");
    formattedText.replace(strikeRegex, "<s>\\1</s>");

    // Замена переносов строк на HTML-переносы
    formattedText.replace("\n", "<br>");

    return formattedText;
}

void CoursesPage::markLessonAsCompleted(int lessonId, int courseId) {
    int userId = getUserIdByUsername(currentUserName);

    // Проверяем, существует ли запись для данного урока и пользователя
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM user_progress WHERE user_id = ? AND lesson_id = ?");
    checkQuery.addBindValue(userId);
    checkQuery.addBindValue(lessonId);

    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() == 0) {
        // Если записи нет, вставляем новую запись
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO user_progress (user_id, lesson_id, completed, course_id, completed_at) "
                            "VALUES (?, ?, ?, ?, CURRENT_TIMESTAMP)");
        insertQuery.addBindValue(userId);
        insertQuery.addBindValue(lessonId);
        insertQuery.addBindValue(1);  // Устанавливаем `completed` как true
        insertQuery.addBindValue(courseId);

        if (!insertQuery.exec()) {
            QMessageBox::warning(this, "Ошибка", "Ошибка записи выполнения урока: " + insertQuery.lastError().text());
        } else {
            qDebug() << "Урок с ID " << lessonId << " завершен";
            

        }
    } else {
        QMessageBox::information(this, "Информация", "Этот урок уже был завершен.");
        
    }
}

void CoursesPage::on_completeLessonButton_clicked()
{
    int row = ui->lessonsTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите урок для завершения.");
        return;
    }

    int lessonId = ui->lessonsTable->item(row, 0)->data(Qt::UserRole).toInt();
    int courseId = ui->coursesTable->item(ui->coursesTable->currentRow(), 0)->data(Qt::UserRole).toInt();

    markLessonAsCompleted(lessonId, courseId);

}

