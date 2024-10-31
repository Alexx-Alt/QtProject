#include "studentprosmotr.h"
#include "ui_studentprosmotr.h"
#include "jwt.h"
#include "prosmotrprofile.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QDebug>

StudentProsmotr::StudentProsmotr(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::StudentProsmotr)
{
    ui->setupUi(this);
    displayStudentsForTeacher();
    //connect(ui->studentListWidget, &QListWidget::itemDoubleClicked, this, &StudentProsmotr::on_studentListWidget_itemDoubleClicked);
    connect(ui->studentListWidget, &QListWidget::itemClicked, this, &StudentProsmotr::on_forumListWidget_itemClicked);

    
    
}

StudentProsmotr::~StudentProsmotr()
{
    delete ui;
}

QByteArray StudentProsmotr::base64UrlDecode(const QString &input) {
    QString base64 = input;
    base64.replace('-', '+');
    base64.replace('_', '/');

    // Pad the string with '=' until it's a multiple of 4 bytes
    while (base64.size() % 4 != 0) {
        base64.append('=');
    }

    return QByteArray::fromBase64(base64.toUtf8());
}

void StudentProsmotr::displayStudentsForTeacher() {
    QString storedToken = QSettings("MyApp", "MyAppName").value("userToken").toString();
    if (storedToken.isEmpty()) {
        return;
    }

    try {
        QStringList tokenParts = storedToken.split('.');
        if (tokenParts.size() != 3) {
            throw std::runtime_error("Invalid token format");
        }

        QByteArray payloadJson = base64UrlDecode(tokenParts[1]);
        QJsonDocument payloadDoc = QJsonDocument::fromJson(payloadJson);

        if (payloadDoc.isNull()) {
            throw std::runtime_error("Failed to decode token");
        }

        QJsonObject payload = payloadDoc.object();
        QString username = payload["username"].toString();
        if (username.isEmpty()) {
            throw std::runtime_error("Token does not contain username");
        }

        QString secretKey = getUserSecretKey(username);
        if (!JWT::verify(storedToken, secretKey)) {
            throw std::runtime_error("Invalid token signature");
        }

        qint64 expirationTime = payload["exp"].toVariant().toLongLong();
        if (QDateTime::fromSecsSinceEpoch(expirationTime) <= QDateTime::currentDateTime()) {
            throw std::runtime_error("Token has expired");
        }

        // Get teacher ID by username
        QSqlQuery query;
        query.prepare("SELECT id FROM users WHERE username = :username");
        query.bindValue(":username", username);

        if (!query.exec() || !query.next()) {
            QMessageBox::critical(this, "Error", "Failed to get teacher ID: " + query.lastError().text());
            return;
        }

        int teacherId = query.value(0).toInt();

        // Get list of students
        query.prepare("SELECT us.username FROM student_teacher st "
                      "JOIN users us ON st.student_id = us.id "
                      "WHERE st.teacher_id = :teacher_id");
        query.bindValue(":teacher_id", teacherId);

        if (!query.exec()) {
            QMessageBox::critical(this, "Error", "Failed to execute query: " + query.lastError().text());
            return;
        }

        while (query.next()) {
            QString studentName = query.value(0).toString();
            ui->studentListWidget->addItem(studentName);
        }
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", QString("Error while checking token: %1").arg(e.what()));
    }
}
// Function to retrieve the user's secret key
QString StudentProsmotr::getUserSecretKey(const QString &username) {
    QSqlQuery query;
    query.prepare("SELECT secret_key FROM users WHERE username = ?");
    query.addBindValue(username);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    } else {
        qCritical() << "Failed to retrieve secret key:" << query.lastError().text();
        return {};
    }
}
void StudentProsmotr::on_forumListWidget_itemClicked(QListWidgetItem *item)
{
    QString username = item->text();
    QSqlQuery query;
   query.prepare("SELECT u.email, COUNT(DISTINCT up.course_id) AS completed_courses, COUNT(DISTINCT up.lesson_id) AS completed_lessons, COUNT(DISTINCT tr.id) AS completed_tests, GROUP_CONCAT(DISTINCT ts.title SEPARATOR ', ') AS tags "
                   "FROM users u "
                   "JOIN user_progress up ON u.id = up.user_id "
                   "JOIN test_results tr ON up.user_id = tr.user_id "
                   "JOIN user_tegs ut ON u.id = ut.user_id "
                   "JOIN tegs_storage ts ON ut.tegs_id = ts.id "
                   "WHERE u.username = ? "
                   "GROUP BY u.id");
    query.addBindValue(username);

    if (query.exec() && query.next()) {
        QString email = query.value(0).toString();
        int completedCourses = query.value(1).toInt();
        int completedLessons = query.value(2).toInt();
        int completedTests = query.value(3).toInt();
        QString tags = query.value(4).toString();

        profile = new ProsmotrProfile(this);
        profile->setProfileInfo(username, email, completedCourses, completedLessons, completedTests, tags);
        profile->setGeometry(750, 50, 401, 381);
        profile->show();
    } else {
        QMessageBox::critical(this, "Error", "User profile not found: " + query.lastError().text());
    }
}
