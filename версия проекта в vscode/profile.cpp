#include "profile.h"
#include "ui_profile.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QHttpMultiPart>

Profile::Profile(const QString &username, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::Profile)
    , currentUserName(username)
    , manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    int userId = getUserIdByUsername(currentUserName);
    fetchUserLevelAndExperience(userId);
    fetchuserregs(userId);
    avatr(userId);
}

Profile::~Profile()
{
    delete ui;
}
//функция получения Id пользователя по его username
int Profile::getUserIdByUsername(const QString &username) {
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
void Profile::fetchUserLevelAndExperience(int userId) {
    QSqlQuery query;
    query.prepare("SELECT level FROM users WHERE id = ?");
    query.addBindValue(userId);

    if (query.exec() && query.next()) {
        int level = query.value("level").toInt();
        ui->userlabel->setText("Имя: " + currentUserName + "! Текущий уровень: " + QString::number(level));
    } else {
        qDebug() << "Ошибка получения уровня и очков опыта:" << query.lastError().text();
    }

}

//функция для вывода тегов пользователя
void Profile::fetchuserregs(int userId)
{
    QSqlQuery query;
    QString str;
    query.prepare("SELECT tegs_storage.title FROM lern.user_tegs "
                        "join tegs_storage "
                        "ON user_tegs.tegs_id=tegs_storage.id "
                        "Where user_tegs.user_id = ? " );
    query.addBindValue(userId);
    if (query.exec()) {
        QStringList tags; // Список для хранения тегов
        while (query.next()) {
            QString tag = query.value(0).toString().trimmed();
            tags.append(tag); // Добавляем тег в список
        }

        // Объединяем все теги в одну строку, разделяя их запятыми
        str = tags.join(", ");
        qDebug() << str;

        ui->tegslabel->setText(str); // Устанавливаем текст на метку
    } else {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text(); // Выводим ошибку
    }
}
void Profile::avatr(int userId){

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

void Profile::on_uploadavatar_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, "Выберите аватар", QString(), "Images (*.png *.jpg *.jpeg *.bmp)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray avatarData = file.readAll();
            file.close();

            // Получаем ID пользователя
            int userId = getUserIdByUsername(currentUserName); // Предполагается, что у вас есть функция для получения ID пользователя

            // Создаем имя файла как userID_avatar
            QString avatarFileName = QString("%1_avatar%2").arg(userId).arg(QFileInfo(fileName).suffix().isEmpty() ? "" : "." + QFileInfo(fileName).suffix());
            updateOrAddAvatarPath(userId, "http://alexx2mh.beget.tech/test2/" + avatarFileName);

            // Создаем запрос для загрузки данных на сервер
            QNetworkRequest request(QUrl("http://alexx2mh.beget.tech/test2/upload_avatar.php"));

            // Создаем multipart/form-data
            QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

            // Создаем часть для файла
            QHttpPart filePart;
            filePart.setHeader(QNetworkRequest::ContentTypeHeader, "application/octet-stream"); // Замените на нужный тип изображения, если необходимо
            filePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"file\"; filename=\"" + avatarFileName + "\""));
            filePart.setBody(avatarData);
            multiPart->append(filePart);


            // Отправляем запрос
            QNetworkReply* reply = manager->post(request, multiPart);
            connect(reply, &QNetworkReply::finished, [reply, multiPart, this]() {
                if (reply->error() == QNetworkReply::NoError) {
                    QMessageBox::information(this, "Успех", "Аватар успешно загружен на сервер.");
                } else {
                    QMessageBox::warning(this, "Ошибка", "Не удалось загрузить аватар: " + reply->errorString());
                }
                reply->deleteLater();
                multiPart->deleteLater();
            });
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл.");
        }
    }


}
void Profile::updateOrAddAvatarPath(int userId, const QString &avatarPath) {
    QSqlQuery query;

    // Проверяем, существует ли запись для данного user_id
    query.prepare("SELECT COUNT(*) FROM avatars WHERE user_id = ?");
    query.addBindValue(userId);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();

        if (count > 0) {
            // Если запись существует, обновляем путь к аватару
            query.prepare("UPDATE avatars SET pathtoavatr = ? WHERE user_id = ?");
            query.addBindValue(avatarPath);
            query.addBindValue(userId);
        } else {
            // Если записи нет, добавляем новую
            query.prepare("INSERT INTO avatars (user_id, pathtoavatr) VALUES (?, ?)");
            query.addBindValue(userId);
            query.addBindValue(avatarPath);
        }

        // Выполняем запрос
        if (query.exec()) {
            qDebug() << "Avatar path updated or added successfully.";
        } else {
            qDebug() << "Error updating or adding avatar path:" << query.lastError().text();
        }
    } else {
        qDebug() << "Error checking avatar existence:" << query.lastError().text();
    }
}

