/********************************************************************************
** Form generated from reading UI file 'courseteacher.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSETEACHER_H
#define UI_COURSETEACHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_CourseTeacher
{
public:

    void setupUi(QFrame *CourseTeacher)
    {
        if (CourseTeacher->objectName().isEmpty())
            CourseTeacher->setObjectName("CourseTeacher");
        CourseTeacher->resize(400, 300);

        retranslateUi(CourseTeacher);

        QMetaObject::connectSlotsByName(CourseTeacher);
    } // setupUi

    void retranslateUi(QFrame *CourseTeacher)
    {
        CourseTeacher->setWindowTitle(QCoreApplication::translate("CourseTeacher", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourseTeacher: public Ui_CourseTeacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSETEACHER_H
