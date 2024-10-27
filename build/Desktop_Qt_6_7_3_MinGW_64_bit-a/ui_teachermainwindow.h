/********************************************************************************
** Form generated from reading UI file 'teachermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERMAINWINDOW_H
#define UI_TEACHERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *widget_2;

    void setupUi(QMainWindow *TeacherMainWindow)
    {
        if (TeacherMainWindow->objectName().isEmpty())
            TeacherMainWindow->setObjectName("TeacherMainWindow");
        TeacherMainWindow->resize(1800, 1000);
        TeacherMainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(190, 190, 190);"));
        centralwidget = new QWidget(TeacherMainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(100, 0, 16, 1011));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(100, 70, 1731, 20));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        TeacherMainWindow->setCentralWidget(centralwidget);

        retranslateUi(TeacherMainWindow);

        QMetaObject::connectSlotsByName(TeacherMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TeacherMainWindow)
    {
        TeacherMainWindow->setWindowTitle(QCoreApplication::translate("TeacherMainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherMainWindow: public Ui_TeacherMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERMAINWINDOW_H
