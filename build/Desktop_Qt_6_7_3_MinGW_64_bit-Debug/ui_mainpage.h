/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QWidget *widget_7;
    QLabel *welcomeLabel;
    QWidget *widget_5;
    QLabel *completedCoursesLabel;
    QLabel *completedLessonsLabel;
    QLabel *experienceLabel;
    QLabel *completedTestsLabel;
    QWidget *widget_3;
    QWidget *widget_6;
    QWidget *widget_4;

    void setupUi(QFrame *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName("MainPage");
        MainPage->resize(1681, 901);
        widget_7 = new QWidget(MainPage);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(1320, 630, 331, 271));
        widget_7->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    background: transparent;          /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    border: 1px solid gray;           /* \320\240\320\260\320\274\320\272\320\260 \321\201\320\265\321\200\320\276\320\263\320\276 \321\206\320\262\320\265\321\202\320\260 */\n"
"    border-radius: 10px;              /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"}"));
        welcomeLabel = new QLabel(MainPage);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(50, 30, 851, 21));
        welcomeLabel->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";"));
        widget_5 = new QWidget(MainPage);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(980, 70, 671, 541));
        widget_5->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    background: transparent;          /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    border: 1px solid gray;           /* \320\240\320\260\320\274\320\272\320\260 \321\201\320\265\321\200\320\276\320\263\320\276 \321\206\320\262\320\265\321\202\320\260 */\n"
"    border-radius: 10px;              /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"}"));
        completedCoursesLabel = new QLabel(widget_5);
        completedCoursesLabel->setObjectName("completedCoursesLabel");
        completedCoursesLabel->setGeometry(QRect(20, 10, 321, 31));
        completedCoursesLabel->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";"));
        completedLessonsLabel = new QLabel(widget_5);
        completedLessonsLabel->setObjectName("completedLessonsLabel");
        completedLessonsLabel->setGeometry(QRect(20, 50, 321, 31));
        completedLessonsLabel->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";"));
        experienceLabel = new QLabel(widget_5);
        experienceLabel->setObjectName("experienceLabel");
        experienceLabel->setGeometry(QRect(20, 90, 321, 31));
        experienceLabel->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";"));
        completedTestsLabel = new QLabel(widget_5);
        completedTestsLabel->setObjectName("completedTestsLabel");
        completedTestsLabel->setGeometry(QRect(20, 130, 321, 31));
        completedTestsLabel->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";"));
        widget_3 = new QWidget(MainPage);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(30, 70, 931, 541));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    background: transparent;          /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    border: 1px solid gray;           /* \320\240\320\260\320\274\320\272\320\260 \321\201\320\265\321\200\320\276\320\263\320\276 \321\206\320\262\320\265\321\202\320\260 */\n"
"    border-radius: 10px;              /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"}"));
        widget_6 = new QWidget(MainPage);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(980, 630, 321, 271));
        widget_6->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    background: transparent;          /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    border: 1px solid gray;           /* \320\240\320\260\320\274\320\272\320\260 \321\201\320\265\321\200\320\276\320\263\320\276 \321\206\320\262\320\265\321\202\320\260 */\n"
"    border-radius: 10px;              /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"}"));
        widget_4 = new QWidget(MainPage);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(30, 630, 931, 271));
        widget_4->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    background: transparent;          /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    border: 1px solid gray;           /* \320\240\320\260\320\274\320\272\320\260 \321\201\320\265\321\200\320\276\320\263\320\276 \321\206\320\262\320\265\321\202\320\260 */\n"
"    border-radius: 10px;              /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"}"));

        retranslateUi(MainPage);

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QFrame *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "Frame", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainPage", "TextLabel", nullptr));
        completedCoursesLabel->setText(QCoreApplication::translate("MainPage", "TextLabel", nullptr));
        completedLessonsLabel->setText(QCoreApplication::translate("MainPage", "TextLabel", nullptr));
        experienceLabel->setText(QCoreApplication::translate("MainPage", "TextLabel", nullptr));
        completedTestsLabel->setText(QCoreApplication::translate("MainPage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
