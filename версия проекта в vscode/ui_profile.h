/********************************************************************************
** Form generated from reading UI file 'profile.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_H
#define UI_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Profile
{
public:
    QLabel *userlabel;
    QLabel *tegslabel;
    QLabel *avatarLabel;
    QPushButton *uploadavatar;

    void setupUi(QFrame *Profile)
    {
        if (Profile->objectName().isEmpty())
            Profile->setObjectName("Profile");
        Profile->resize(755, 701);
        userlabel = new QLabel(Profile);
        userlabel->setObjectName("userlabel");
        userlabel->setGeometry(QRect(40, 40, 311, 41));
        userlabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        tegslabel = new QLabel(Profile);
        tegslabel->setObjectName("tegslabel");
        tegslabel->setGeometry(QRect(130, 220, 481, 121));
        avatarLabel = new QLabel(Profile);
        avatarLabel->setObjectName("avatarLabel");
        avatarLabel->setGeometry(QRect(370, 100, 111, 101));
        uploadavatar = new QPushButton(Profile);
        uploadavatar->setObjectName("uploadavatar");
        uploadavatar->setGeometry(QRect(440, 440, 80, 24));

        retranslateUi(Profile);

        QMetaObject::connectSlotsByName(Profile);
    } // setupUi

    void retranslateUi(QFrame *Profile)
    {
        Profile->setWindowTitle(QCoreApplication::translate("Profile", "Frame", nullptr));
        userlabel->setText(QCoreApplication::translate("Profile", "TextLabel", nullptr));
        tegslabel->setText(QCoreApplication::translate("Profile", "TextLabel", nullptr));
        avatarLabel->setText(QCoreApplication::translate("Profile", "TextLabel", nullptr));
        uploadavatar->setText(QCoreApplication::translate("Profile", "\320\241\320\274\320\265\320\275\320\260 \320\260\320\262\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Profile: public Ui_Profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H
