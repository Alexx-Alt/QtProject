/********************************************************************************
** Form generated from reading UI file 'teasherstudentframe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEASHERSTUDENTFRAME_H
#define UI_TEASHERSTUDENTFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_TeasherStudentFrame
{
public:

    void setupUi(QFrame *TeasherStudentFrame)
    {
        if (TeasherStudentFrame->objectName().isEmpty())
            TeasherStudentFrame->setObjectName("TeasherStudentFrame");
        TeasherStudentFrame->resize(693, 462);

        retranslateUi(TeasherStudentFrame);

        QMetaObject::connectSlotsByName(TeasherStudentFrame);
    } // setupUi

    void retranslateUi(QFrame *TeasherStudentFrame)
    {
        TeasherStudentFrame->setWindowTitle(QCoreApplication::translate("TeasherStudentFrame", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeasherStudentFrame: public Ui_TeasherStudentFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEASHERSTUDENTFRAME_H
