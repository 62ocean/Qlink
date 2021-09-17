/********************************************************************************
** Form generated from reading UI file 'singlemainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLEMAINWIN_H
#define UI_SINGLEMAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleMainWin
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SingleMainWin)
    {
        if (SingleMainWin->objectName().isEmpty())
            SingleMainWin->setObjectName(QString::fromUtf8("SingleMainWin"));
        SingleMainWin->resize(1200, 900);
        SingleMainWin->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(SingleMainWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SingleMainWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SingleMainWin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 26));
        SingleMainWin->setMenuBar(menubar);
        statusbar = new QStatusBar(SingleMainWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SingleMainWin->setStatusBar(statusbar);

        retranslateUi(SingleMainWin);

        QMetaObject::connectSlotsByName(SingleMainWin);
    } // setupUi

    void retranslateUi(QMainWindow *SingleMainWin)
    {
        SingleMainWin->setWindowTitle(QCoreApplication::translate("SingleMainWin", "Qlink-\345\215\225\344\272\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingleMainWin: public Ui_SingleMainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLEMAINWIN_H
