#ifndef STUDENTPROSMOTR_H
#define STUDENTPROSMOTR_H

#include <QFrame>

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

    void displayStudentsForTeacher();

    QString getUserSecretKey(const QString &token);
};

#endif // STUDENTPROSMOTR_H
