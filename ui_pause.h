/********************************************************************************
** Form generated from reading UI file 'pause.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSE_H
#define UI_PAUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pause
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QPushButton *openmenuButton;
    QPushButton *continueButton;

    void setupUi(QDialog *Pause)
    {
        if (Pause->objectName().isEmpty())
            Pause->setObjectName(QString::fromUtf8("Pause"));
        Pause->resize(312, 150);
        label = new QLabel(Pause);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 120, 291, 21));
        layoutWidget = new QWidget(Pause);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 21, 291, 91));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout->addWidget(saveButton, 0, 0, 1, 1);

        loadButton = new QPushButton(layoutWidget);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));

        gridLayout->addWidget(loadButton, 0, 1, 1, 1);

        openmenuButton = new QPushButton(layoutWidget);
        openmenuButton->setObjectName(QString::fromUtf8("openmenuButton"));

        gridLayout->addWidget(openmenuButton, 1, 0, 1, 1);

        continueButton = new QPushButton(layoutWidget);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setCheckable(false);

        gridLayout->addWidget(continueButton, 1, 1, 1, 1);


        retranslateUi(Pause);

        continueButton->setDefault(true);


        QMetaObject::connectSlotsByName(Pause);
    } // setupUi

    void retranslateUi(QDialog *Pause)
    {
        Pause->setWindowTitle(QCoreApplication::translate("Pause", "\346\232\202\345\201\234", nullptr));
        label->setText(QString());
        saveButton->setText(QCoreApplication::translate("Pause", "\344\277\235\345\255\230\346\270\270\346\210\217", nullptr));
        loadButton->setText(QCoreApplication::translate("Pause", "\350\275\275\345\205\245\346\270\270\346\210\217", nullptr));
        openmenuButton->setText(QCoreApplication::translate("Pause", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
        continueButton->setText(QCoreApplication::translate("Pause", "\347\273\247\347\273\255\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pause: public Ui_Pause {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_H
