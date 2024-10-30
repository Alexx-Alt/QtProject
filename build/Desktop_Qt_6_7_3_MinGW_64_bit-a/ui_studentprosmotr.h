/********************************************************************************
** Form generated from reading UI file 'studentprosmotr.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTPROSMOTR_H
#define UI_STUDENTPROSMOTR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentProsmotr
{
public:
    QTableWidget *studentWidget;
    QListWidget *studentListWidget;
    QLabel *studentListLabel;

    void setupUi(QFrame *StudentProsmotr)
    {
        if (StudentProsmotr->objectName().isEmpty())
            StudentProsmotr->setObjectName("StudentProsmotr");
        StudentProsmotr->resize(780, 696);
        studentWidget = new QTableWidget(StudentProsmotr);
        studentWidget->setObjectName("studentWidget");
        studentWidget->setGeometry(QRect(140, 130, 256, 192));
        studentListWidget = new QListWidget(StudentProsmotr);
        studentListWidget->setObjectName("studentListWidget");
        studentListWidget->setGeometry(QRect(250, 450, 256, 192));
        studentListLabel = new QLabel(StudentProsmotr);
        studentListLabel->setObjectName("studentListLabel");
        studentListLabel->setGeometry(QRect(490, 100, 45, 15));

        retranslateUi(StudentProsmotr);

        QMetaObject::connectSlotsByName(StudentProsmotr);
    } // setupUi

    void retranslateUi(QFrame *StudentProsmotr)
    {
        StudentProsmotr->setWindowTitle(QCoreApplication::translate("StudentProsmotr", "Frame", nullptr));
        studentListLabel->setText(QCoreApplication::translate("StudentProsmotr", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentProsmotr: public Ui_StudentProsmotr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTPROSMOTR_H
