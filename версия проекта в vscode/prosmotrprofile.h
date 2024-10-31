#ifndef PROSMOTRPROFILE_H
#define PROSMOTRPROFILE_H

#include <QFrame>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

namespace Ui {
class ProsmotrProfile;
}

class ProsmotrProfile : public QFrame
{
    Q_OBJECT

public:
    explicit ProsmotrProfile(QWidget *parent = nullptr);
    ~ProsmotrProfile();
    void setProfileInfo(const QString &username, const QString &email, int completedCourses, int completedLessons, int completedTests, QString tags);

    void avatr(const QString &username);

private:
    Ui::ProsmotrProfile *ui;

    QNetworkAccessManager* manager;

    int getUserIdByUsername(const QString &username);
};

#endif // PROSMOTRPROFILE_H
