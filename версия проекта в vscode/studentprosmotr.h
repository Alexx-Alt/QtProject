#ifndef STUDENTPROSMOTR_H
#define STUDENTPROSMOTR_H

#include <QFrame>
#include "prosmotrprofile.h"
#include <QListWidget>

namespace Ui {
class StudentProsmotr;
}

class StudentProsmotr : public QFrame
{
    Q_OBJECT

public:
    explicit StudentProsmotr(QWidget *parent = nullptr);
    ~StudentProsmotr();

private:
    Ui::StudentProsmotr *ui;

    ProsmotrProfile* profile;

    void displayStudentsForTeacher();

    QString getUserSecretKey(const QString &token);

    QByteArray  base64UrlDecode(const QString &base64Url);

    void on_forumListWidget_itemClicked(QListWidgetItem *item);
};

#endif // STUDENTPROSMOTR_H
