#ifndef PROFILE_H
#define PROFILE_H

#include <QFrame>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

namespace Ui {
class Profile;
}

class Profile : public QFrame
{
    Q_OBJECT

public:
    explicit Profile(const QString &username,QWidget *parent = nullptr);
    ~Profile();

private slots:
    void on_uploadavatar_clicked();

private:
    Ui::Profile *ui;

    QString currentUserName;

    QNetworkAccessManager* manager;

    int getUserIdByUsername(const QString &username);

    void fetchUserLevelAndExperience(int userId);

    void fetchuserregs(int userId);

    void avatr(int userId);

    void updateOrAddAvatarPath(int userId, const QString &avatarPath);
};

#endif // PROFILE_H
