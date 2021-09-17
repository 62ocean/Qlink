/********************************************************************************
** Form generated from reading UI file 'doublesetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLESETTING_H
#define UI_DOUBLESETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoubleSetting
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpinBox *widthBox;
    QLabel *label_6;
    QLabel *label_5;
    QSpinBox *heightBox;
    QLabel *label_7;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *boxNumBox;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSpinBox *timeBox;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *button1;
    QRadioButton *button2;
    QRadioButton *button3;
    QLabel *label_12;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_3;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *role1Button;
    QRadioButton *role2Button;
    QRadioButton *role3Button;
    QRadioButton *role4Button;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *role1Button_2;
    QRadioButton *role2Button_2;
    QRadioButton *role3Button_2;
    QRadioButton *role4Button_2;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *hintLabel;
    QLabel *label_20;
    QLabel *label_21;

    void setupUi(QDialog *DoubleSetting)
    {
        if (DoubleSetting->objectName().isEmpty())
            DoubleSetting->setObjectName(QString::fromUtf8("DoubleSetting"));
        DoubleSetting->resize(558, 590);
        layoutWidget = new QWidget(DoubleSetting);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 40, 441, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font.setPointSize(14);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setTextFormat(Qt::AutoText);
        label->setMargin(0);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widthBox = new QSpinBox(layoutWidget);
        widthBox->setObjectName(QString::fromUtf8("widthBox"));
        widthBox->setMinimum(10);
        widthBox->setMaximum(30);
        widthBox->setValue(20);

        horizontalLayout->addWidget(widthBox);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);

        heightBox = new QSpinBox(layoutWidget);
        heightBox->setObjectName(QString::fromUtf8("heightBox"));
        heightBox->setMinimum(10);
        heightBox->setMaximum(30);
        heightBox->setValue(15);

        horizontalLayout->addWidget(heightBox);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_7);

        layoutWidget_2 = new QWidget(DoubleSetting);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(40, 100, 441, 51));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        boxNumBox = new QSpinBox(layoutWidget_2);
        boxNumBox->setObjectName(QString::fromUtf8("boxNumBox"));
        boxNumBox->setMinimum(5);
        boxNumBox->setMaximum(15);
        boxNumBox->setValue(7);

        horizontalLayout_2->addWidget(boxNumBox);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        label_19 = new QLabel(layoutWidget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_4->addWidget(label_19);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        timeBox = new QSpinBox(layoutWidget_2);
        timeBox->setObjectName(QString::fromUtf8("timeBox"));
        timeBox->setMaximum(999);
        timeBox->setValue(120);

        horizontalLayout_5->addWidget(timeBox);


        horizontalLayout_4->addLayout(horizontalLayout_5);

        layoutWidget_3 = new QWidget(DoubleSetting);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(40, 160, 441, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        horizontalLayout_3->addWidget(label_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        button1 = new QRadioButton(layoutWidget_3);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setChecked(false);

        horizontalLayout_3->addWidget(button1);

        button2 = new QRadioButton(layoutWidget_3);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setChecked(true);

        horizontalLayout_3->addWidget(button2);

        button3 = new QRadioButton(layoutWidget_3);
        button3->setObjectName(QString::fromUtf8("button3"));

        horizontalLayout_3->addWidget(button3);

        label_12 = new QLabel(DoubleSetting);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(420, 300, 41, 41));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/res/role4.png")));
        label_12->setScaledContents(true);
        label_9 = new QLabel(DoubleSetting);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(90, 300, 41, 41));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/res/role1.png")));
        label_9->setScaledContents(true);
        label_10 = new QLabel(DoubleSetting);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(200, 300, 41, 41));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/res/role2.png")));
        label_10->setScaledContents(true);
        label_11 = new QLabel(DoubleSetting);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(310, 300, 41, 41));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/res/role3.png")));
        label_11->setScaledContents(true);
        label_3 = new QLabel(DoubleSetting);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 220, 101, 31));
        label_3->setFont(font);
        label_13 = new QLabel(DoubleSetting);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(90, 430, 41, 41));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/res/role1.png")));
        label_13->setScaledContents(true);
        label_14 = new QLabel(DoubleSetting);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(310, 430, 41, 41));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/res/role3.png")));
        label_14->setScaledContents(true);
        label_15 = new QLabel(DoubleSetting);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(200, 430, 41, 41));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/res/role2.png")));
        label_15->setScaledContents(true);
        label_16 = new QLabel(DoubleSetting);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(420, 430, 41, 41));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/res/role4.png")));
        label_16->setScaledContents(true);
        label_17 = new QLabel(DoubleSetting);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(60, 390, 101, 31));
        label_17->setFont(font);
        label_18 = new QLabel(DoubleSetting);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(60, 260, 101, 31));
        label_18->setFont(font);
        layoutWidget_4 = new QWidget(DoubleSetting);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(90, 350, 441, 21));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        role1Button = new QRadioButton(layoutWidget_4);
        role1Button->setObjectName(QString::fromUtf8("role1Button"));
        role1Button->setChecked(true);

        horizontalLayout_7->addWidget(role1Button);

        role2Button = new QRadioButton(layoutWidget_4);
        role2Button->setObjectName(QString::fromUtf8("role2Button"));

        horizontalLayout_7->addWidget(role2Button);

        role3Button = new QRadioButton(layoutWidget_4);
        role3Button->setObjectName(QString::fromUtf8("role3Button"));
        role3Button->setChecked(false);

        horizontalLayout_7->addWidget(role3Button);

        role4Button = new QRadioButton(layoutWidget_4);
        role4Button->setObjectName(QString::fromUtf8("role4Button"));
        role4Button->setChecked(false);

        horizontalLayout_7->addWidget(role4Button);

        layoutWidget_5 = new QWidget(DoubleSetting);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(90, 480, 441, 21));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        role1Button_2 = new QRadioButton(layoutWidget_5);
        role1Button_2->setObjectName(QString::fromUtf8("role1Button_2"));
        role1Button_2->setChecked(false);

        horizontalLayout_8->addWidget(role1Button_2);

        role2Button_2 = new QRadioButton(layoutWidget_5);
        role2Button_2->setObjectName(QString::fromUtf8("role2Button_2"));
        role2Button_2->setChecked(true);

        horizontalLayout_8->addWidget(role2Button_2);

        role3Button_2 = new QRadioButton(layoutWidget_5);
        role3Button_2->setObjectName(QString::fromUtf8("role3Button_2"));
        role3Button_2->setChecked(false);

        horizontalLayout_8->addWidget(role3Button_2);

        role4Button_2 = new QRadioButton(layoutWidget_5);
        role4Button_2->setObjectName(QString::fromUtf8("role4Button_2"));
        role4Button_2->setChecked(false);

        horizontalLayout_8->addWidget(role4Button_2);

        layoutWidget_6 = new QWidget(DoubleSetting);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(320, 530, 231, 41));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(layoutWidget_6);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_6->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget_6);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_6->addWidget(cancelButton);

        hintLabel = new QLabel(DoubleSetting);
        hintLabel->setObjectName(QString::fromUtf8("hintLabel"));
        hintLabel->setGeometry(QRect(30, 520, 241, 31));
        label_20 = new QLabel(DoubleSetting);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(490, 40, 56, 49));
        label_21 = new QLabel(DoubleSetting);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(490, 100, 56, 49));

        retranslateUi(DoubleSetting);

        QMetaObject::connectSlotsByName(DoubleSetting);
    } // setupUi

    void retranslateUi(QDialog *DoubleSetting)
    {
        DoubleSetting->setWindowTitle(QCoreApplication::translate("DoubleSetting", "\345\217\214\344\272\272\346\250\241\345\274\217\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("DoubleSetting", "\345\234\260\345\233\276\345\244\247\345\260\217", nullptr));
        label_6->setText(QCoreApplication::translate("DoubleSetting", "\351\225\277", nullptr));
        label_5->setText(QCoreApplication::translate("DoubleSetting", "\303\227", nullptr));
        label_7->setText(QCoreApplication::translate("DoubleSetting", "\351\253\230", nullptr));
        label_2->setText(QCoreApplication::translate("DoubleSetting", "\346\226\271\345\235\227\347\247\215\347\261\273\346\225\260", nullptr));
        label_19->setText(QCoreApplication::translate("DoubleSetting", "(5-15)", nullptr));
        label_4->setText(QCoreApplication::translate("DoubleSetting", "\346\270\270\346\210\217\346\227\266\351\225\277 (s)", nullptr));
        label_8->setText(QCoreApplication::translate("DoubleSetting", "\346\226\271\345\235\227\345\257\206\351\233\206\347\250\213\345\272\246", nullptr));
        button1->setText(QCoreApplication::translate("DoubleSetting", "\347\250\200\347\226\217", nullptr));
        button2->setText(QCoreApplication::translate("DoubleSetting", "\346\231\256\351\200\232", nullptr));
        button3->setText(QCoreApplication::translate("DoubleSetting", "\345\257\206\351\233\206", nullptr));
        label_12->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_3->setText(QCoreApplication::translate("DoubleSetting", "\344\272\272\347\211\251\351\200\211\346\213\251", nullptr));
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
        label_17->setText(QCoreApplication::translate("DoubleSetting", "player2", nullptr));
        label_18->setText(QCoreApplication::translate("DoubleSetting", "player1", nullptr));
        role1Button->setText(QCoreApplication::translate("DoubleSetting", "\345\267\253\345\270\210", nullptr));
        role2Button->setText(QCoreApplication::translate("DoubleSetting", "\345\277\215\350\200\205", nullptr));
        role3Button->setText(QCoreApplication::translate("DoubleSetting", "\347\245\255\345\217\270", nullptr));
        role4Button->setText(QCoreApplication::translate("DoubleSetting", "\346\210\230\345\243\253", nullptr));
        role1Button_2->setText(QCoreApplication::translate("DoubleSetting", "\345\267\253\345\270\210", nullptr));
        role2Button_2->setText(QCoreApplication::translate("DoubleSetting", "\345\277\215\350\200\205", nullptr));
        role3Button_2->setText(QCoreApplication::translate("DoubleSetting", "\347\245\255\345\217\270", nullptr));
        role4Button_2->setText(QCoreApplication::translate("DoubleSetting", "\346\210\230\345\243\253", nullptr));
        okButton->setText(QCoreApplication::translate("DoubleSetting", "\350\277\233\345\205\245\346\270\270\346\210\217", nullptr));
        cancelButton->setText(QCoreApplication::translate("DoubleSetting", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        hintLabel->setText(QString());
        label_20->setText(QCoreApplication::translate("DoubleSetting", "(10-30)", nullptr));
        label_21->setText(QCoreApplication::translate("DoubleSetting", "(0-999)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoubleSetting: public Ui_DoubleSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLESETTING_H
