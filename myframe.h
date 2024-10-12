#ifndef MYFRAME_H
#define MYFRAME_H

#include <QFrame>

namespace Ui {
class MyFrame;
}

class MyFrame : public QFrame
{
    Q_OBJECT

public:
    explicit MyFrame(QWidget *parent = nullptr);
    ~MyFrame();

private:
    Ui::MyFrame *ui;
};

#endif // MYFRAME_H
