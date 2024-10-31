#ifndef USERPROFILEDIALOG_H
#define USERPROFILEDIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

namespace Ui {
class UserProfileDialog;
}

class UserProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserProfileDialog(QWidget *parent = nullptr);
    ~UserProfileDialog();

    void setProfileInfo(const QString &username, const QString &email, int completedCourses, int completedLessons, int completedTests);

private:
    Ui::UserProfileDialog *ui;

    QNetworkAccessManager* manager;

    void avatr(const QString &username);
};

#endif // USERPROFILEDIALOG_H
