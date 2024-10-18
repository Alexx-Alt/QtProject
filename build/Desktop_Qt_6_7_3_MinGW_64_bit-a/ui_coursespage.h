/********************************************************************************
** Form generated from reading UI file 'coursespage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSESPAGE_H
#define UI_COURSESPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CoursesPage
{
public:
    QTableWidget *coursesTable;
    QTableWidget *lessonsTable;

    void setupUi(QFrame *CoursesPage)
    {
        if (CoursesPage->objectName().isEmpty())
            CoursesPage->setObjectName("CoursesPage");
        CoursesPage->resize(605, 589);
        coursesTable = new QTableWidget(CoursesPage);
        coursesTable->setObjectName("coursesTable");
        coursesTable->setGeometry(QRect(140, 100, 441, 221));
        lessonsTable = new QTableWidget(CoursesPage);
        lessonsTable->setObjectName("lessonsTable");
        lessonsTable->setGeometry(QRect(110, 360, 481, 192));

        retranslateUi(CoursesPage);

        QMetaObject::connectSlotsByName(CoursesPage);
    } // setupUi

    void retranslateUi(QFrame *CoursesPage)
    {
        CoursesPage->setWindowTitle(QCoreApplication::translate("CoursesPage", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CoursesPage: public Ui_CoursesPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSESPAGE_H
