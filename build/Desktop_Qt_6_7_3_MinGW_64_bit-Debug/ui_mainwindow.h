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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *menuwidget;
    QPushButton *pushButton;
    QWidget *widget;
    QLabel *menulabel;

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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        menuwidget = new QWidget(centralwidget);
        menuwidget->setObjectName("menuwidget");
        menuwidget->setGeometry(QRect(0, 0, 71, 1001));
        menuwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 215, 216);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(176, 230, 40, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        widget->setGeometry(QRect(70, 0, 1731, 80));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 247);"));
        menulabel = new QLabel(centralwidget);
        menulabel->setObjectName("menulabel");
        menulabel->setEnabled(true);
        menulabel->setGeometry(QRect(180, 230, 31, 31));
        MainWindow->setCentralWidget(centralwidget);
        menulabel->raise();
        menuwidget->raise();
        pushButton->raise();
        widget->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QString());
        menulabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
