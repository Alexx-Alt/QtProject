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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CoursesPage
{
public:
    QTableWidget *coursesTable;
    QTableWidget *lessonsTable;
    QTextEdit *lessontextedit;
    QPushButton *completeLessonButton;

    void setupUi(QFrame *CoursesPage)
    {
        if (CoursesPage->objectName().isEmpty())
            CoursesPage->setObjectName("CoursesPage");
        CoursesPage->resize(1436, 789);
        coursesTable = new QTableWidget(CoursesPage);
        coursesTable->setObjectName("coursesTable");
        coursesTable->setGeometry(QRect(140, 100, 441, 221));
        lessonsTable = new QTableWidget(CoursesPage);
        lessonsTable->setObjectName("lessonsTable");
        lessonsTable->setGeometry(QRect(110, 360, 481, 192));
        lessontextedit = new QTextEdit(CoursesPage);
        lessontextedit->setObjectName("lessontextedit");
        lessontextedit->setGeometry(QRect(640, 360, 531, 351));
        completeLessonButton = new QPushButton(CoursesPage);
        completeLessonButton->setObjectName("completeLessonButton");
        completeLessonButton->setGeometry(QRect(1230, 600, 131, 41));

        retranslateUi(CoursesPage);

        QMetaObject::connectSlotsByName(CoursesPage);
    } // setupUi

    void retranslateUi(QFrame *CoursesPage)
    {
        CoursesPage->setWindowTitle(QCoreApplication::translate("CoursesPage", "Frame", nullptr));
        completeLessonButton->setText(QCoreApplication::translate("CoursesPage", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \321\203\321\200\320\276\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CoursesPage: public Ui_CoursesPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSESPAGE_H
