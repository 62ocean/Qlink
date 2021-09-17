/********************************************************************************
** Form generated from reading UI file 'openmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENMENU_H
#define UI_OPENMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_OpenMenu
{
public:
    QPushButton *startButton;
    QPushButton *loadButton;
    QPushButton *helpButton;
    QPushButton *exitButton;
    QLabel *label;

    void setupUi(QDialog *OpenMenu)
    {
        if (OpenMenu->objectName().isEmpty())
            OpenMenu->setObjectName(QString::fromUtf8("OpenMenu"));
        OpenMenu->resize(599, 565);
        OpenMenu->setStyleSheet(QString::fromUtf8("background-image: url(:/res/open.jpg);"));
        startButton = new QPushButton(OpenMenu);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(220, 200, 131, 31));
        loadButton = new QPushButton(OpenMenu);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(220, 250, 131, 31));
        helpButton = new QPushButton(OpenMenu);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setGeometry(QRect(220, 300, 131, 31));
        exitButton = new QPushButton(OpenMenu);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(220, 350, 131, 31));
        label = new QLabel(OpenMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 60, 211, 21));

        retranslateUi(OpenMenu);

        QMetaObject::connectSlotsByName(OpenMenu);
    } // setupUi

    void retranslateUi(QDialog *OpenMenu)
    {
        OpenMenu->setWindowTitle(QCoreApplication::translate("OpenMenu", "Qlink", nullptr));
        startButton->setText(QCoreApplication::translate("OpenMenu", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        loadButton->setText(QCoreApplication::translate("OpenMenu", "\350\275\275\345\205\245\346\270\270\346\210\217", nullptr));
        helpButton->setText(QCoreApplication::translate("OpenMenu", "\346\200\216\344\271\210\347\216\251\357\274\237", nullptr));
        exitButton->setText(QCoreApplication::translate("OpenMenu", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        label->setText(QCoreApplication::translate("OpenMenu", "\346\262\241\346\234\211\345\217\257\344\276\233\350\275\275\345\205\245\347\232\204\345\255\230\346\241\243\345\223\246\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenMenu: public Ui_OpenMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENMENU_H
