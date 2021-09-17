/********************************************************************************
** Form generated from reading UI file 'choosemodel.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEMODEL_H
#define UI_CHOOSEMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChooseModel
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *singleButton;
    QPushButton *doubleButton;
    QPushButton *returnButton;

    void setupUi(QDialog *ChooseModel)
    {
        if (ChooseModel->objectName().isEmpty())
            ChooseModel->setObjectName(QString::fromUtf8("ChooseModel"));
        ChooseModel->resize(200, 148);
        verticalLayout = new QVBoxLayout(ChooseModel);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        singleButton = new QPushButton(ChooseModel);
        singleButton->setObjectName(QString::fromUtf8("singleButton"));

        verticalLayout->addWidget(singleButton);

        doubleButton = new QPushButton(ChooseModel);
        doubleButton->setObjectName(QString::fromUtf8("doubleButton"));

        verticalLayout->addWidget(doubleButton);

        returnButton = new QPushButton(ChooseModel);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));

        verticalLayout->addWidget(returnButton);


        retranslateUi(ChooseModel);

        QMetaObject::connectSlotsByName(ChooseModel);
    } // setupUi

    void retranslateUi(QDialog *ChooseModel)
    {
        ChooseModel->setWindowTitle(QCoreApplication::translate("ChooseModel", "\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));
        singleButton->setText(QCoreApplication::translate("ChooseModel", "\345\215\225\344\272\272\346\250\241\345\274\217", nullptr));
        doubleButton->setText(QCoreApplication::translate("ChooseModel", "\345\217\214\344\272\272\346\250\241\345\274\217", nullptr));
        returnButton->setText(QCoreApplication::translate("ChooseModel", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseModel: public Ui_ChooseModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEMODEL_H
