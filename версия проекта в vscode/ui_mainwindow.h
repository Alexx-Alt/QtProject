/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *maimpagebutton;
    QWidget *widget;
    QLabel *menulabel;
    QWidget *widget_2;
    QLabel *booklabel;
    QPushButton *menutestbutton;
    QLabel *upmenuHome;
    QFrame *testframe;
    QPushButton *pushButton;
    QLabel *avatarLabel;
    QPushButton *avatar;
    QLabel *courselabel;
    QPushButton *menucoursebutton;
    QLabel *upmenuTest;
    QPushButton *pushButton_4;
    QPushButton *ProfileButton;
    QPushButton *forumbutton;
    QPushButton *logoutButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1800, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1800, 1000));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        maimpagebutton = new QPushButton(centralwidget);
        maimpagebutton->setObjectName("maimpagebutton");
        maimpagebutton->setGeometry(QRect(30, 190, 41, 41));
        maimpagebutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;    /* \320\241\320\264\320\265\320\273\320\260\321\202\321\214 \321\204\320\276\320\275 \320\272\320\275\320\276\320\277\320\272\320\270 \320\277\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\274 */\n"
"    border: none;                     /* \320\243\320\261\321\200\320\260\321\202\321\214 \321\200\320\260\320\274\320\272\321\203, \320\265\321\201\320\273\320\270 \320\275\320\265 \320\275\321\203\320\266\320\275\320\260 */\n"
"    color: white;                     /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    font-size: 16px;                  /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    padding: 10px;                    /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   "
                        " background-color: rgba(255, 255, 255, 0.2); /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 (\320\277\320\276\320\273\321\203\320\277\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271) */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.4); /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 (\320\261\320\276\320\273\320\265\320\265 \321\202\320\265\320\274\320\275\321\213\320\271 \320\277\320\276\320\273\321\203\320\277\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271) */\n"
"}\n"
""));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(100, 0, 16, 1011));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        menulabel = new QLabel(centralwidget);
        menulabel->setObjectName("menulabel");
        menulabel->setEnabled(true);
        menulabel->setGeometry(QRect(30, 190, 41, 41));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(100, 70, 1731, 20));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        booklabel = new QLabel(centralwidget);
        booklabel->setObjectName("booklabel");
        booklabel->setGeometry(QRect(30, 260, 41, 41));
        menutestbutton = new QPushButton(centralwidget);
        menutestbutton->setObjectName("menutestbutton");
        menutestbutton->setGeometry(QRect(30, 260, 41, 41));
        menutestbutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;    /* \320\241\320\264\320\265\320\273\320\260\321\202\321\214 \321\204\320\276\320\275 \320\272\320\275\320\276\320\277\320\272\320\270 \320\277\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\274 */\n"
"    border: none;                     /* \320\243\320\261\321\200\320\260\321\202\321\214 \321\200\320\260\320\274\320\272\321\203, \320\265\321\201\320\273\320\270 \320\275\320\265 \320\275\321\203\320\266\320\275\320\260 */\n"
"    color: white;                     /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    font-size: 16px;                  /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    padding: 10px;                    /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   "
                        " background-color: rgba(255, 255, 255, 0.2); /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 (\320\277\320\276\320\273\321\203\320\277\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271) */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.4); /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 (\320\261\320\276\320\273\320\265\320\265 \321\202\320\265\320\274\320\275\321\213\320\271 \320\277\320\276\320\273\321\203\320\277\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271) */\n"
"}\n"
""));
        upmenuHome = new QLabel(centralwidget);
        upmenuHome->setObjectName("upmenuHome");
        upmenuHome->setGeometry(QRect(140, 20, 81, 21));
        upmenuHome->setStyleSheet(QString::fromUtf8("font:  14pt \"Segoe UI\";\n"
""));
        testframe = new QFrame(centralwidget);
        testframe->setObjectName("testframe");
        testframe->setGeometry(QRect(120, 90, 1681, 901));
        testframe->setFrameShape(QFrame::Shape::StyledPanel);
        testframe->setFrameShadow(QFrame::Shadow::Raised);
        pushButton = new QPushButton(testframe);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 120, 80, 24));
        avatarLabel = new QLabel(testframe);
        avatarLabel->setObjectName("avatarLabel");
        avatarLabel->setGeometry(QRect(360, 90, 211, 101));
        avatar = new QPushButton(testframe);
        avatar->setObjectName("avatar");
        avatar->setGeometry(QRect(100, 200, 80, 22));
        courselabel = new QLabel(centralwidget);
        courselabel->setObjectName("courselabel");
        courselabel->setGeometry(QRect(30, 330, 41, 41));
        menucoursebutton = new QPushButton(centralwidget);
        menucoursebutton->setObjectName("menucoursebutton");
        menucoursebutton->setGeometry(QRect(30, 330, 51, 51));
        menucoursebutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;    /* \320\241\320\264\320\265\320\273\320\260\321\202\321\214 \321\204\320\276\320\275 \320\272\320\275\320\276\320\277\320\272\320\270 \320\277\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\274 */\n"
"    border: none;                     /* \320\243\320\261\321\200\320\260\321\202\321\214 \321\200\320\260\320\274\320\272\321\203, \320\265\321\201\320\273\320\270 \320\275\320\265 \320\275\321\203\320\266\320\275\320\260 */\n"
"    color: white;                     /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    font-size: 16px;                  /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    padding: 10px;                    /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   "
                        " background-color: rgba(255, 255, 255, 0.2); /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 (\320\277\320\276\320\273\321\203\320\277\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271) */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.4); /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 (\320\261\320\276\320\273\320\265\320\265 \321\202\320\265\320\274\320\275\321\213\320\271 \320\277\320\276\320\273\321\203\320\277\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271) */\n"
"}\n"
""));
        upmenuTest = new QLabel(centralwidget);
        upmenuTest->setObjectName("upmenuTest");
        upmenuTest->setGeometry(QRect(250, 20, 81, 21));
        upmenuTest->setStyleSheet(QString::fromUtf8("font:  14pt \"Segoe UI\";\n"
""));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 430, 80, 22));
        ProfileButton = new QPushButton(centralwidget);
        ProfileButton->setObjectName("ProfileButton");
        ProfileButton->setGeometry(QRect(10, 480, 80, 22));
        forumbutton = new QPushButton(centralwidget);
        forumbutton->setObjectName("forumbutton");
        forumbutton->setGeometry(QRect(10, 530, 80, 24));
        logoutButton = new QPushButton(centralwidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(10, 650, 80, 22));
        MainWindow->setCentralWidget(centralwidget);
        courselabel->raise();
        menucoursebutton->raise();
        testframe->raise();
        booklabel->raise();
        menutestbutton->raise();
        menulabel->raise();
        maimpagebutton->raise();
        widget->raise();
        widget_2->raise();
        upmenuHome->raise();
        upmenuTest->raise();
        pushButton_4->raise();
        ProfileButton->raise();
        forumbutton->raise();
        logoutButton->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        maimpagebutton->setText(QString());
        menulabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        booklabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menutestbutton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        upmenuHome->setText(QCoreApplication::translate("MainWindow", "\320\223\320\273\320\260\320\262\320\275\320\260\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        avatarLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        avatar->setText(QCoreApplication::translate("MainWindow", "\320\260\320\262\320\260\321\202\320\260\321\200\320\272\320\260", nullptr));
        courselabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menucoursebutton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        upmenuTest->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\321\213", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        ProfileButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\204\320\270\320\273\321\214", nullptr));
        forumbutton->setText(QCoreApplication::translate("MainWindow", "\321\204\320\276\321\200\321\203\320\274", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
