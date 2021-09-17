/********************************************************************************
** Form generated from reading UI file 'singlesetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLESETTING_H
#define UI_SINGLESETTING_H

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

class Ui_SingleSetting
{
public:
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *role1Button;
    QRadioButton *role2Button;
    QRadioButton *role3Button;
    QRadioButton *role4Button;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpinBox *widthBox;
    QLabel *label_6;
    QLabel *label_5;
    QSpinBox *heightBox;
    QLabel *label_7;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *boxNumBox;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSpinBox *timeBox;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *button1;
    QRadioButton *button2;
    QRadioButton *button3;
    QLabel *label_20;
    QLabel *label_21;

    void setupUi(QDialog *SingleSetting)
    {
        if (SingleSetting->objectName().isEmpty())
            SingleSetting->setObjectName(QString::fromUtf8("SingleSetting"));
        SingleSetting->resize(532, 384);
        label_3 = new QLabel(SingleSetting);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 210, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font.setPointSize(14);
        label_3->setFont(font);
        label_9 = new QLabel(SingleSetting);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 250, 41, 41));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/res/role1.png")));
        label_9->setScaledContents(true);
        label_10 = new QLabel(SingleSetting);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(160, 250, 41, 41));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/res/role2.png")));
        label_10->setScaledContents(true);
        label_11 = new QLabel(SingleSetting);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(280, 250, 41, 41));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/res/role3.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(SingleSetting);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(390, 250, 41, 41));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/res/role4.png")));
        label_12->setScaledContents(true);
        layoutWidget = new QWidget(SingleSetting);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 330, 231, 41));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_6->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_6->addWidget(cancelButton);

        layoutWidget1 = new QWidget(SingleSetting);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 290, 451, 31));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        role1Button = new QRadioButton(layoutWidget1);
        role1Button->setObjectName(QString::fromUtf8("role1Button"));
        role1Button->setChecked(true);

        horizontalLayout_7->addWidget(role1Button);

        role2Button = new QRadioButton(layoutWidget1);
        role2Button->setObjectName(QString::fromUtf8("role2Button"));

        horizontalLayout_7->addWidget(role2Button);

        role3Button = new QRadioButton(layoutWidget1);
        role3Button->setObjectName(QString::fromUtf8("role3Button"));
        role3Button->setChecked(false);

        horizontalLayout_7->addWidget(role3Button);

        role4Button = new QRadioButton(layoutWidget1);
        role4Button->setObjectName(QString::fromUtf8("role4Button"));
        role4Button->setChecked(false);

        horizontalLayout_7->addWidget(role4Button);

        layoutWidget2 = new QWidget(SingleSetting);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 30, 441, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setTextFormat(Qt::AutoText);
        label->setMargin(0);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widthBox = new QSpinBox(layoutWidget2);
        widthBox->setObjectName(QString::fromUtf8("widthBox"));
        widthBox->setMinimum(10);
        widthBox->setMaximum(30);
        widthBox->setValue(20);

        horizontalLayout->addWidget(widthBox);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);

        heightBox = new QSpinBox(layoutWidget2);
        heightBox->setObjectName(QString::fromUtf8("heightBox"));
        heightBox->setMinimum(10);
        heightBox->setMaximum(30);
        heightBox->setValue(15);

        horizontalLayout->addWidget(heightBox);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_7);

        layoutWidget3 = new QWidget(SingleSetting);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 90, 441, 51));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        boxNumBox = new QSpinBox(layoutWidget3);
        boxNumBox->setObjectName(QString::fromUtf8("boxNumBox"));
        boxNumBox->setMinimum(5);
        boxNumBox->setMaximum(15);
        boxNumBox->setValue(7);

        horizontalLayout_2->addWidget(boxNumBox);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        label_22 = new QLabel(layoutWidget3);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_4->addWidget(label_22);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        timeBox = new QSpinBox(layoutWidget3);
        timeBox->setObjectName(QString::fromUtf8("timeBox"));
        timeBox->setMaximum(999);
        timeBox->setValue(120);

        horizontalLayout_5->addWidget(timeBox);


        horizontalLayout_4->addLayout(horizontalLayout_5);

        layoutWidget4 = new QWidget(SingleSetting);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 150, 441, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        horizontalLayout_3->addWidget(label_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        button1 = new QRadioButton(layoutWidget4);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setChecked(false);

        horizontalLayout_3->addWidget(button1);

        button2 = new QRadioButton(layoutWidget4);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setChecked(true);

        horizontalLayout_3->addWidget(button2);

        button3 = new QRadioButton(layoutWidget4);
        button3->setObjectName(QString::fromUtf8("button3"));

        horizontalLayout_3->addWidget(button3);

        label_20 = new QLabel(SingleSetting);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(470, 30, 56, 49));
        label_21 = new QLabel(SingleSetting);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(470, 90, 56, 49));

        retranslateUi(SingleSetting);

        QMetaObject::connectSlotsByName(SingleSetting);
    } // setupUi

    void retranslateUi(QDialog *SingleSetting)
    {
        SingleSetting->setWindowTitle(QCoreApplication::translate("SingleSetting", "\345\215\225\344\272\272\346\250\241\345\274\217\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("SingleSetting", "\344\272\272\347\211\251\351\200\211\346\213\251", nullptr));
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        okButton->setText(QCoreApplication::translate("SingleSetting", "\350\277\233\345\205\245\346\270\270\346\210\217", nullptr));
        cancelButton->setText(QCoreApplication::translate("SingleSetting", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        role1Button->setText(QCoreApplication::translate("SingleSetting", "\345\267\253\345\270\210", nullptr));
        role2Button->setText(QCoreApplication::translate("SingleSetting", "\345\277\215\350\200\205", nullptr));
        role3Button->setText(QCoreApplication::translate("SingleSetting", "\347\245\255\345\217\270", nullptr));
        role4Button->setText(QCoreApplication::translate("SingleSetting", "\346\210\230\345\243\253", nullptr));
        label->setText(QCoreApplication::translate("SingleSetting", "\345\234\260\345\233\276\345\244\247\345\260\217", nullptr));
        label_6->setText(QCoreApplication::translate("SingleSetting", "\351\225\277", nullptr));
        label_5->setText(QCoreApplication::translate("SingleSetting", "\303\227", nullptr));
        label_7->setText(QCoreApplication::translate("SingleSetting", "\351\253\230", nullptr));
        label_2->setText(QCoreApplication::translate("SingleSetting", "\346\226\271\345\235\227\347\247\215\347\261\273\346\225\260", nullptr));
        label_22->setText(QCoreApplication::translate("SingleSetting", "(5-15)", nullptr));
        label_4->setText(QCoreApplication::translate("SingleSetting", "\346\270\270\346\210\217\346\227\266\351\225\277 (s)", nullptr));
        label_8->setText(QCoreApplication::translate("SingleSetting", "\346\226\271\345\235\227\345\257\206\351\233\206\347\250\213\345\272\246", nullptr));
        button1->setText(QCoreApplication::translate("SingleSetting", "\347\250\200\347\226\217", nullptr));
        button2->setText(QCoreApplication::translate("SingleSetting", "\346\231\256\351\200\232", nullptr));
        button3->setText(QCoreApplication::translate("SingleSetting", "\345\257\206\351\233\206", nullptr));
        label_20->setText(QCoreApplication::translate("SingleSetting", "(10-30)", nullptr));
        label_21->setText(QCoreApplication::translate("SingleSetting", "(0-999)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingleSetting: public Ui_SingleSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLESETTING_H
