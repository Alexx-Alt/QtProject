#ifndef PROFILE_H
#define PROFILE_H

#include <QFrame>

namespace Ui {
class Profile;
}

class Profile : public QFrame
{
    Q_OBJECT

public:
    explicit Profile(const QString &username,QWidget *parent = nullptr);
    ~Profile();

private:
    Ui::Profile *ui;

    QString currentUserName;

    int getUserIdByUsername(const QString &username);

    void fetchUserLevelAndExperience(int userId);

    void fetchuserregs(int userId);
};

#endif // PROFILE_H
