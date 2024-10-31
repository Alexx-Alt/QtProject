#ifndef TEASHERSTUDENTFRAME_H
#define TEASHERSTUDENTFRAME_H

#include <QFrame>

namespace Ui {
class TeasherStudentFrame;
}

class TeasherStudentFrame : public QFrame
{
    Q_OBJECT

public:
    explicit TeasherStudentFrame(QWidget *parent = nullptr);
    ~TeasherStudentFrame();

private:
    Ui::TeasherStudentFrame *ui;
};

#endif // TEASHERSTUDENTFRAME_H
