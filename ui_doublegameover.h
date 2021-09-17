/********************************************************************************
** Form generated from reading UI file 'doublegameover.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLEGAMEOVER_H
#define UI_DOUBLEGAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoubleGameover
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *player1;
    QLabel *scoreLabel1;
    QLabel *label_4;
    QLabel *player2;
    QLabel *scoreLabel2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *winner;
    QLabel *winLabel;

    void setupUi(QDialog *DoubleGameover)
    {
        if (DoubleGameover->objectName().isEmpty())
            DoubleGameover->setObjectName(QString::fromUtf8("DoubleGameover"));
        DoubleGameover->resize(381, 279);
        label = new QLabel(DoubleGameover);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 291, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(12);
        label->setFont(font);
        pushButton = new QPushButton(DoubleGameover);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 220, 93, 28));
        layoutWidget = new QWidget(DoubleGameover);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 80, 301, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        player1 = new QLabel(layoutWidget);
        player1->setObjectName(QString::fromUtf8("player1"));

        horizontalLayout->addWidget(player1);

        scoreLabel1 = new QLabel(layoutWidget);
        scoreLabel1->setObjectName(QString::fromUtf8("scoreLabel1"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(14);
        scoreLabel1->setFont(font1);
        scoreLabel1->setTextFormat(Qt::AutoText);

        horizontalLayout->addWidget(scoreLabel1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setTextFormat(Qt::AutoText);

        horizontalLayout->addWidget(label_4);

        player2 = new QLabel(layoutWidget);
        player2->setObjectName(QString::fromUtf8("player2"));

        horizontalLayout->addWidget(player2);

        scoreLabel2 = new QLabel(layoutWidget);
        scoreLabel2->setObjectName(QString::fromUtf8("scoreLabel2"));
        scoreLabel2->setFont(font1);
        scoreLabel2->setTextFormat(Qt::AutoText);

        horizontalLayout->addWidget(scoreLabel2);

        layoutWidget1 = new QWidget(DoubleGameover);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(120, 150, 131, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        winner = new QLabel(layoutWidget1);
        winner->setObjectName(QString::fromUtf8("winner"));

        horizontalLayout_2->addWidget(winner);

        winLabel = new QLabel(layoutWidget1);
        winLabel->setObjectName(QString::fromUtf8("winLabel"));
        winLabel->setFont(font1);
        winLabel->setTextFormat(Qt::AutoText);

        horizontalLayout_2->addWidget(winLabel);


        retranslateUi(DoubleGameover);

        QMetaObject::connectSlotsByName(DoubleGameover);
    } // setupUi

    void retranslateUi(QDialog *DoubleGameover)
    {
        DoubleGameover->setWindowTitle(QCoreApplication::translate("DoubleGameover", "\346\270\270\346\210\217\347\273\223\346\235\237", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("DoubleGameover", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        player1->setText(QString());
        scoreLabel1->setText(QString());
        label_4->setText(QCoreApplication::translate("DoubleGameover", "VS", nullptr));
        player2->setText(QString());
        scoreLabel2->setText(QString());
        winner->setText(QString());
        winLabel->setText(QCoreApplication::translate("DoubleGameover", "\350\265\242\344\272\206\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoubleGameover: public Ui_DoubleGameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLEGAMEOVER_H
