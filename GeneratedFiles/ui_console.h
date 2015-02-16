/********************************************************************************
** Form generated from reading UI file 'console.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_console
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;

    void setupUi(QDialog *console)
    {
        if (console->objectName().isEmpty())
            console->setObjectName(QStringLiteral("console"));
        console->resize(486, 364);
        verticalLayout = new QVBoxLayout(console);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(console);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setAcceptRichText(false);

        verticalLayout->addWidget(textBrowser);

        lineEdit = new QLineEdit(console);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        retranslateUi(console);

        QMetaObject::connectSlotsByName(console);
    } // setupUi

    void retranslateUi(QDialog *console)
    {
        console->setWindowTitle(QApplication::translate("console", "console", 0));
    } // retranslateUi

};

namespace Ui {
    class console: public Ui_console {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLE_H
