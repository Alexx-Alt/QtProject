/********************************************************************************
** Form generated from reading UI file 'testframe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTFRAME_H
#define UI_TESTFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TestFrame
{
public:
    QLabel *statusLabel;
    QPushButton *finishTestButton;
    QLabel *questionLabel;
    QComboBox *testComboBox;
    QLineEdit *answerInput;
    QPushButton *nextQuestionButton;
    QPushButton *startTestButton;

    void setupUi(QFrame *TestFrame)
    {
        if (TestFrame->objectName().isEmpty())
            TestFrame->setObjectName("TestFrame");
        TestFrame->resize(1681, 901);
        statusLabel = new QLabel(TestFrame);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(810, 70, 111, 41));
        finishTestButton = new QPushButton(TestFrame);
        finishTestButton->setObjectName("finishTestButton");
        finishTestButton->setGeometry(QRect(640, 110, 80, 22));
        questionLabel = new QLabel(TestFrame);
        questionLabel->setObjectName("questionLabel");
        questionLabel->setGeometry(QRect(100, 70, 341, 41));
        testComboBox = new QComboBox(TestFrame);
        testComboBox->setObjectName("testComboBox");
        testComboBox->setGeometry(QRect(480, 60, 221, 23));
        answerInput = new QLineEdit(TestFrame);
        answerInput->setObjectName("answerInput");
        answerInput->setGeometry(QRect(90, 140, 113, 23));
        nextQuestionButton = new QPushButton(TestFrame);
        nextQuestionButton->setObjectName("nextQuestionButton");
        nextQuestionButton->setGeometry(QRect(490, 130, 80, 22));
        startTestButton = new QPushButton(TestFrame);
        startTestButton->setObjectName("startTestButton");
        startTestButton->setGeometry(QRect(420, 180, 80, 22));

        retranslateUi(TestFrame);

        QMetaObject::connectSlotsByName(TestFrame);
    } // setupUi

    void retranslateUi(QFrame *TestFrame)
    {
        TestFrame->setWindowTitle(QCoreApplication::translate("TestFrame", "Frame", nullptr));
        statusLabel->setText(QCoreApplication::translate("TestFrame", "TextLabel", nullptr));
        finishTestButton->setText(QCoreApplication::translate("TestFrame", "\320\244\320\270\320\275\320\270\321\210", nullptr));
        questionLabel->setText(QCoreApplication::translate("TestFrame", "TextLabel", nullptr));
        nextQuestionButton->setText(QCoreApplication::translate("TestFrame", "\320\241\320\273\320\265\320\264", nullptr));
        startTestButton->setText(QCoreApplication::translate("TestFrame", "\320\241\321\202\320\260\321\200\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestFrame: public Ui_TestFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTFRAME_H
