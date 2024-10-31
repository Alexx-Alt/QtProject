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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *widget_2;
    QPushButton *studentbutton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QPushButton *logoutbutton;

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
        studentbutton = new QPushButton(centralwidget);
        studentbutton->setObjectName("studentbutton");
        studentbutton->setGeometry(QRect(20, 130, 61, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 200, 61, 51));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 260, 61, 51));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 160, 151, 81));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";\n"
"background-color: rgb(255, 255, 255);"));
        logoutbutton = new QPushButton(centralwidget);
        logoutbutton->setObjectName("logoutbutton");
        logoutbutton->setGeometry(QRect(20, 690, 61, 41));
        TeacherMainWindow->setCentralWidget(centralwidget);

        retranslateUi(TeacherMainWindow);

        QMetaObject::connectSlotsByName(TeacherMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TeacherMainWindow)
    {
        TeacherMainWindow->setWindowTitle(QCoreApplication::translate("TeacherMainWindow", "MainWindow", nullptr));
        studentbutton->setText(QCoreApplication::translate("TeacherMainWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("TeacherMainWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("TeacherMainWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("TeacherMainWindow", "TextLabel", nullptr));
        logoutbutton->setText(QCoreApplication::translate("TeacherMainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherMainWindow: public Ui_TeacherMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERMAINWINDOW_H
