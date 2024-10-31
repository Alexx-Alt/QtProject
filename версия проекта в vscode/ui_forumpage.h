/********************************************************************************
** Form generated from reading UI file 'forumpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORUMPAGE_H
#define UI_FORUMPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ForumPage
{
public:
    QListWidget *forumListWidget;
    QPushButton *addQuestionButton;
    QTextEdit *newQuestionTextEdit;
    QPushButton *addAnswerButton;
    QTextEdit *newAnswerTextEdit;
    QTextEdit *selectedQuestionTextEdit;
    QListWidget *answersListWidget;
    QPushButton *showUserProfile;

    void setupUi(QFrame *ForumPage)
    {
        if (ForumPage->objectName().isEmpty())
            ForumPage->setObjectName("ForumPage");
        ForumPage->resize(1342, 1019);
        forumListWidget = new QListWidget(ForumPage);
        forumListWidget->setObjectName("forumListWidget");
        forumListWidget->setGeometry(QRect(250, 230, 441, 321));
        addQuestionButton = new QPushButton(ForumPage);
        addQuestionButton->setObjectName("addQuestionButton");
        addQuestionButton->setGeometry(QRect(360, 100, 80, 24));
        newQuestionTextEdit = new QTextEdit(ForumPage);
        newQuestionTextEdit->setObjectName("newQuestionTextEdit");
        newQuestionTextEdit->setGeometry(QRect(80, 230, 161, 111));
        addAnswerButton = new QPushButton(ForumPage);
        addAnswerButton->setObjectName("addAnswerButton");
        addAnswerButton->setGeometry(QRect(560, 130, 80, 24));
        newAnswerTextEdit = new QTextEdit(ForumPage);
        newAnswerTextEdit->setObjectName("newAnswerTextEdit");
        newAnswerTextEdit->setGeometry(QRect(710, 220, 161, 111));
        selectedQuestionTextEdit = new QTextEdit(ForumPage);
        selectedQuestionTextEdit->setObjectName("selectedQuestionTextEdit");
        selectedQuestionTextEdit->setGeometry(QRect(890, 220, 431, 401));
        answersListWidget = new QListWidget(ForumPage);
        answersListWidget->setObjectName("answersListWidget");
        answersListWidget->setGeometry(QRect(900, 630, 256, 192));
        showUserProfile = new QPushButton(ForumPage);
        showUserProfile->setObjectName("showUserProfile");
        showUserProfile->setGeometry(QRect(1180, 640, 131, 24));

        retranslateUi(ForumPage);

        QMetaObject::connectSlotsByName(ForumPage);
    } // setupUi

    void retranslateUi(QFrame *ForumPage)
    {
        ForumPage->setWindowTitle(QCoreApplication::translate("ForumPage", "Frame", nullptr));
        addQuestionButton->setText(QCoreApplication::translate("ForumPage", "\320\262\320\276\320\277\321\200\320\276\321\201", nullptr));
        addAnswerButton->setText(QCoreApplication::translate("ForumPage", "\320\276\321\202\320\262\320\265\321\202", nullptr));
        showUserProfile->setText(QCoreApplication::translate("ForumPage", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\277\321\200\320\276\321\204\320\270\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForumPage: public Ui_ForumPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORUMPAGE_H
