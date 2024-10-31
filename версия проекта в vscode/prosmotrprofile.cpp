#include "prosmotrprofile.h"
#include "ui_prosmotrprofile.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QMessageBox>



ProsmotrProfile::ProsmotrProfile(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::ProsmotrProfile)
    , manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    
}

ProsmotrProfile::~ProsmotrProfile()
{
    delete ui;
}
void ProsmotrProfile::setProfileInfo(const QString &username, const QString &email, int completedCourses, int completedLessons, int completedTests, QString tags)
{
    ui->usernameLabel->setText("Имя пользователя: " + username);
    ui->emailLabel->setText(email);
    ui->completedCoursesLabel->setText("Количество выполненных курсов: " + QString::number(completedCourses));
    ui->completedLessonsLabel->setText("Количество выполненных уроков: " + QString::number(completedLessons));
    ui->completedTestsLabel->setText("Количество выполненных тестов: " + QString::number(completedTests));
    ui->tegsLabel->setText("Теги: " + tags);
    avatr(username);
}
void ProsmotrProfile::avatr(const QString &username){
    QString name = username;
    // Получение пути к аватарке из базы данных
    QSqlQuery query;
    query.prepare("SELECT pathtoavatr FROM avatars WHERE user_id = (SELECT id FROM users WHERE username = ?)");
    query.addBindValue(name);

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
