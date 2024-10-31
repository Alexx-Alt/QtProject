/********************************************************************************
** Form generated from reading UI file 'prosmotrprofile.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROSMOTRPROFILE_H
#define UI_PROSMOTRPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProsmotrProfile
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *avatarLabel;
    QLabel *usernameLabel;
    QLabel *completedCoursesLabel;
    QLabel *emailLabel;
    QLabel *completedLessonsLabel;
    QLabel *completedTestsLabel;
    QLabel *tegsLabel;

    void setupUi(QFrame *ProsmotrProfile)
    {
        if (ProsmotrProfile->objectName().isEmpty())
            ProsmotrProfile->setObjectName("ProsmotrProfile");
        ProsmotrProfile->resize(602, 556);
        verticalLayout = new QVBoxLayout(ProsmotrProfile);
        verticalLayout->setObjectName("verticalLayout");
        avatarLabel = new QLabel(ProsmotrProfile);
        avatarLabel->setObjectName("avatarLabel");

        verticalLayout->addWidget(avatarLabel);

        usernameLabel = new QLabel(ProsmotrProfile);
        usernameLabel->setObjectName("usernameLabel");
        QFont font;
        font.setPointSize(18);
        usernameLabel->setFont(font);

        verticalLayout->addWidget(usernameLabel);

        completedCoursesLabel = new QLabel(ProsmotrProfile);
        completedCoursesLabel->setObjectName("completedCoursesLabel");

        verticalLayout->addWidget(completedCoursesLabel);

        emailLabel = new QLabel(ProsmotrProfile);
        emailLabel->setObjectName("emailLabel");

        verticalLayout->addWidget(emailLabel);

        completedLessonsLabel = new QLabel(ProsmotrProfile);
        completedLessonsLabel->setObjectName("completedLessonsLabel");

        verticalLayout->addWidget(completedLessonsLabel);

        completedTestsLabel = new QLabel(ProsmotrProfile);
        completedTestsLabel->setObjectName("completedTestsLabel");

        verticalLayout->addWidget(completedTestsLabel);

        tegsLabel = new QLabel(ProsmotrProfile);
        tegsLabel->setObjectName("tegsLabel");

        verticalLayout->addWidget(tegsLabel);


        retranslateUi(ProsmotrProfile);

        QMetaObject::connectSlotsByName(ProsmotrProfile);
    } // setupUi

    void retranslateUi(QFrame *ProsmotrProfile)
    {
        ProsmotrProfile->setWindowTitle(QCoreApplication::translate("ProsmotrProfile", "Frame", nullptr));
        avatarLabel->setText(QString());
        usernameLabel->setText(QCoreApplication::translate("ProsmotrProfile", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        completedCoursesLabel->setText(QCoreApplication::translate("ProsmotrProfile", "\320\232\321\203\321\200\321\201\321\213: 0", nullptr));
        emailLabel->setText(QCoreApplication::translate("ProsmotrProfile", "email", nullptr));
        completedLessonsLabel->setText(QCoreApplication::translate("ProsmotrProfile", "\320\243\321\200\320\276\320\272\320\270: 0", nullptr));
        completedTestsLabel->setText(QCoreApplication::translate("ProsmotrProfile", "\320\242\320\265\321\201\321\202\321\213: 0", nullptr));
        tegsLabel->setText(QCoreApplication::translate("ProsmotrProfile", "\320\242\320\265\320\263\320\270: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProsmotrProfile: public Ui_ProsmotrProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROSMOTRPROFILE_H
