/********************************************************************************
** Form generated from reading UI file 'teachermain.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERMAIN_H
#define UI_TEACHERMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_Teachermain
{
public:

    void setupUi(QFrame *Teachermain)
    {
        if (Teachermain->objectName().isEmpty())
            Teachermain->setObjectName("Teachermain");
        Teachermain->resize(869, 600);

        retranslateUi(Teachermain);

        QMetaObject::connectSlotsByName(Teachermain);
    } // setupUi

    void retranslateUi(QFrame *Teachermain)
    {
        Teachermain->setWindowTitle(QCoreApplication::translate("Teachermain", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Teachermain: public Ui_Teachermain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERMAIN_H
