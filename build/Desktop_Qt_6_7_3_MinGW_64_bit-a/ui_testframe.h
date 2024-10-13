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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestFrame
{
public:
    QWidget *widget_3;
    QLineEdit *answerInput;
    QLabel *questionLabel;
    QPushButton *startTestButton;
    QPushButton *nextQuestionButton;
    QPushButton *finishTestButton;
    QLabel *statusLabel;
    QComboBox *testComboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *widget_6;
    QTableWidget *resultsTable;

    void setupUi(QFrame *TestFrame)
    {
        if (TestFrame->objectName().isEmpty())
            TestFrame->setObjectName("TestFrame");
        TestFrame->resize(1681, 901);
        widget_3 = new QWidget(TestFrame);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(20, 20, 931, 541));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    background: transparent;          /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    border: 1px solid gray;           /* \320\240\320\260\320\274\320\272\320\260 \321\201\320\265\321\200\320\276\320\263\320\276 \321\206\320\262\320\265\321\202\320\260 */\n"
"    border-radius: 10px;              /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"}"));
        answerInput = new QLineEdit(widget_3);
        answerInput->setObjectName("answerInput");
        answerInput->setGeometry(QRect(230, 190, 113, 23));
        questionLabel = new QLabel(widget_3);
        questionLabel->setObjectName("questionLabel");
        questionLabel->setGeometry(QRect(220, 110, 321, 31));
        startTestButton = new QPushButton(widget_3);
        startTestButton->setObjectName("startTestButton");
        startTestButton->setGeometry(QRect(470, 50, 80, 22));
        nextQuestionButton = new QPushButton(widget_3);
        nextQuestionButton->setObjectName("nextQuestionButton");
        nextQuestionButton->setGeometry(QRect(370, 190, 80, 22));
        finishTestButton = new QPushButton(widget_3);
        finishTestButton->setObjectName("finishTestButton");
        finishTestButton->setGeometry(QRect(480, 190, 80, 22));
        statusLabel = new QLabel(widget_3);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(700, 110, 121, 21));
        testComboBox = new QComboBox(widget_3);
        testComboBox->setObjectName("testComboBox");
        testComboBox->setGeometry(QRect(220, 50, 221, 23));
        label = new QLabel(widget_3);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 50, 111, 16));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 120, 111, 16));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(580, 110, 111, 16));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 200, 111, 16));
        widget_6 = new QWidget(TestFrame);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(960, 20, 571, 271));
        widget_6->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    background: transparent;          /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    border: 1px solid gray;           /* \320\240\320\260\320\274\320\272\320\260 \321\201\320\265\321\200\320\276\320\263\320\276 \321\206\320\262\320\265\321\202\320\260 */\n"
"    border-radius: 10px;              /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"}"));
        resultsTable = new QTableWidget(TestFrame);
        resultsTable->setObjectName("resultsTable");
        resultsTable->setGeometry(QRect(970, 300, 561, 261));

        retranslateUi(TestFrame);

        QMetaObject::connectSlotsByName(TestFrame);
    } // setupUi

    void retranslateUi(QFrame *TestFrame)
    {
        TestFrame->setWindowTitle(QCoreApplication::translate("TestFrame", "Frame", nullptr));
        questionLabel->setText(QCoreApplication::translate("TestFrame", "TextLabel", nullptr));
        startTestButton->setText(QCoreApplication::translate("TestFrame", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        nextQuestionButton->setText(QCoreApplication::translate("TestFrame", "\320\241\320\273\320\265\320\264", nullptr));
        finishTestButton->setText(QCoreApplication::translate("TestFrame", "\320\244\320\270\320\275\320\270\321\210", nullptr));
        statusLabel->setText(QCoreApplication::translate("TestFrame", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("TestFrame", "\320\222\321\213\320\261\320\276\321\200 \321\202\320\265\321\201\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("TestFrame", "\320\222\320\276\320\277\321\200\320\276\321\201", nullptr));
        label_3->setText(QCoreApplication::translate("TestFrame", "\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("TestFrame", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\321\202\320\262\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestFrame: public Ui_TestFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTFRAME_H
