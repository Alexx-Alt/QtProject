/********************************************************************************
** Form generated from reading UI file 'userprofiledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPROFILEDIALOG_H
#define UI_USERPROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_UserProfileDialog
{
public:
    QLabel *usernameLabel;
    QLabel *emailLabel;
    QLabel *completedCoursesLabel;
    QLabel *completedLessonsLabel;
    QLabel *completedTestsLabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *avatarLabel;

    void setupUi(QDialog *UserProfileDialog)
    {
        if (UserProfileDialog->objectName().isEmpty())
            UserProfileDialog->setObjectName("UserProfileDialog");
        UserProfileDialog->resize(594, 577);
        usernameLabel = new QLabel(UserProfileDialog);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setGeometry(QRect(120, 60, 191, 61));
        emailLabel = new QLabel(UserProfileDialog);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setGeometry(QRect(120, 190, 191, 61));
        completedCoursesLabel = new QLabel(UserProfileDialog);
        completedCoursesLabel->setObjectName("completedCoursesLabel");
        completedCoursesLabel->setGeometry(QRect(120, 130, 191, 61));
        completedLessonsLabel = new QLabel(UserProfileDialog);
        completedLessonsLabel->setObjectName("completedLessonsLabel");
        completedLessonsLabel->setGeometry(QRect(110, 260, 191, 61));
        completedTestsLabel = new QLabel(UserProfileDialog);
        completedTestsLabel->setObjectName("completedTestsLabel");
        completedTestsLabel->setGeometry(QRect(100, 330, 191, 61));
        label = new QLabel(UserProfileDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 80, 49, 16));
        label_2 = new QLabel(UserProfileDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 150, 49, 16));
        label_3 = new QLabel(UserProfileDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 210, 49, 16));
        label_4 = new QLabel(UserProfileDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 290, 49, 16));
        label_5 = new QLabel(UserProfileDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 360, 49, 16));
        avatarLabel = new QLabel(UserProfileDialog);
        avatarLabel->setObjectName("avatarLabel");
        avatarLabel->setGeometry(QRect(330, 110, 121, 81));

        retranslateUi(UserProfileDialog);

        QMetaObject::connectSlotsByName(UserProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *UserProfileDialog)
    {
        UserProfileDialog->setWindowTitle(QCoreApplication::translate("UserProfileDialog", "Dialog", nullptr));
        usernameLabel->setText(QCoreApplication::translate("UserProfileDialog", "TextLabel", nullptr));
        emailLabel->setText(QCoreApplication::translate("UserProfileDialog", "TextLabel", nullptr));
        completedCoursesLabel->setText(QCoreApplication::translate("UserProfileDialog", "TextLabel", nullptr));
        completedLessonsLabel->setText(QCoreApplication::translate("UserProfileDialog", "TextLabel", nullptr));
        completedTestsLabel->setText(QCoreApplication::translate("UserProfileDialog", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("UserProfileDialog", "\320\230\320\274\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("UserProfileDialog", "\320\232\321\203\321\200\321\201\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("UserProfileDialog", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("UserProfileDialog", "\320\243\321\200\320\276\320\272\320\270", nullptr));
        label_5->setText(QCoreApplication::translate("UserProfileDialog", "\320\242\320\265\321\201\321\202\321\213", nullptr));
        avatarLabel->setText(QCoreApplication::translate("UserProfileDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserProfileDialog: public Ui_UserProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPROFILEDIALOG_H
