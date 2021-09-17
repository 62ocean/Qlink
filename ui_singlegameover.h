/********************************************************************************
** Form generated from reading UI file 'singlegameover.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLEGAMEOVER_H
#define UI_SINGLEGAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleGameover
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *scoreLabel;
    QLabel *label_4;

    void setupUi(QDialog *SingleGameover)
    {
        if (SingleGameover->objectName().isEmpty())
            SingleGameover->setObjectName(QString::fromUtf8("SingleGameover"));
        SingleGameover->resize(294, 198);
        label = new QLabel(SingleGameover);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 171, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(12);
        label->setFont(font);
        pushButton = new QPushButton(SingleGameover);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 140, 93, 28));
        layoutWidget = new QWidget(SingleGameover);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 60, 231, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(14);
        label_3->setFont(font1);
        label_3->setTextFormat(Qt::AutoText);

        horizontalLayout->addWidget(label_3);

        scoreLabel = new QLabel(layoutWidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font2.setPointSize(14);
        scoreLabel->setFont(font2);

        horizontalLayout->addWidget(scoreLabel);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout->addWidget(label_4);


        retranslateUi(SingleGameover);

        QMetaObject::connectSlotsByName(SingleGameover);
    } // setupUi

    void retranslateUi(QDialog *SingleGameover)
    {
        SingleGameover->setWindowTitle(QCoreApplication::translate("SingleGameover", "\346\270\270\346\210\217\347\273\223\346\235\237", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("SingleGameover", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        label_3->setText(QCoreApplication::translate("SingleGameover", "\344\275\240\345\276\227\344\272\206", nullptr));
        scoreLabel->setText(QString());
        label_4->setText(QCoreApplication::translate("SingleGameover", "\345\210\206\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingleGameover: public Ui_SingleGameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLEGAMEOVER_H
