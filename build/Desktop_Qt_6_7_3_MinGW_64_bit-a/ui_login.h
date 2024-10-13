/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QFrame *registerframe;
    QLineEdit *NameLabel;
    QLineEdit *EmailLabel;
    QLineEdit *PasswordLabel;
    QPushButton *loginButton;
    QPushButton *backregister;
    QFrame *frame;
    QLineEdit *NameLabel2;
    QLineEdit *PasswordLabel2;
    QPushButton *RegistrationButton;
    QPushButton *LoginButton;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(663, 358);
        registerframe = new QFrame(login);
        registerframe->setObjectName("registerframe");
        registerframe->setGeometry(QRect(330, 50, 281, 231));
        registerframe->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 244, 244);"));
        registerframe->setFrameShape(QFrame::Shape::StyledPanel);
        registerframe->setFrameShadow(QFrame::Shadow::Raised);
        NameLabel = new QLineEdit(registerframe);
        NameLabel->setObjectName("NameLabel");
        NameLabel->setGeometry(QRect(40, 20, 200, 23));
        EmailLabel = new QLineEdit(registerframe);
        EmailLabel->setObjectName("EmailLabel");
        EmailLabel->setGeometry(QRect(40, 60, 200, 23));
        PasswordLabel = new QLineEdit(registerframe);
        PasswordLabel->setObjectName("PasswordLabel");
        PasswordLabel->setGeometry(QRect(40, 100, 200, 23));
        PasswordLabel->setEchoMode(QLineEdit::EchoMode::Password);
        loginButton = new QPushButton(registerframe);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(30, 150, 131, 22));
        backregister = new QPushButton(registerframe);
        backregister->setObjectName("backregister");
        backregister->setGeometry(QRect(60, 180, 80, 22));
        frame = new QFrame(login);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(50, 50, 241, 231));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        NameLabel2 = new QLineEdit(frame);
        NameLabel2->setObjectName("NameLabel2");
        NameLabel2->setGeometry(QRect(50, 20, 141, 23));
        PasswordLabel2 = new QLineEdit(frame);
        PasswordLabel2->setObjectName("PasswordLabel2");
        PasswordLabel2->setGeometry(QRect(50, 60, 141, 23));
        PasswordLabel2->setEchoMode(QLineEdit::EchoMode::Password);
        RegistrationButton = new QPushButton(frame);
        RegistrationButton->setObjectName("RegistrationButton");
        RegistrationButton->setGeometry(QRect(60, 190, 80, 22));
        LoginButton = new QPushButton(frame);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(60, 140, 80, 22));
        frame->raise();
        registerframe->raise();

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "\320\244\320\276\321\200\320\274\320\260 \320\262\321\205\320\276\320\264\320\260", nullptr));
        NameLabel->setPlaceholderText(QCoreApplication::translate("login", "\320\230\320\274\321\217", nullptr));
        EmailLabel->setPlaceholderText(QCoreApplication::translate("login", "\320\255\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\260\321\217 \320\277\320\276\321\207\321\202\320\260", nullptr));
        PasswordLabel->setPlaceholderText(QCoreApplication::translate("login", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        loginButton->setText(QCoreApplication::translate("login", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        backregister->setText(QCoreApplication::translate("login", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        NameLabel2->setPlaceholderText(QCoreApplication::translate("login", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        PasswordLabel2->setPlaceholderText(QCoreApplication::translate("login", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        RegistrationButton->setText(QCoreApplication::translate("login", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        LoginButton->setText(QCoreApplication::translate("login", "\320\222\320\276\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
