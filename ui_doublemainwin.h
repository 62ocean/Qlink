/********************************************************************************
** Form generated from reading UI file 'doublemainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLEMAINWIN_H
#define UI_DOUBLEMAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoubleMainWin
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DoubleMainWin)
    {
        if (DoubleMainWin->objectName().isEmpty())
            DoubleMainWin->setObjectName(QString::fromUtf8("DoubleMainWin"));
        DoubleMainWin->resize(800, 600);
        centralwidget = new QWidget(DoubleMainWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        DoubleMainWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DoubleMainWin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        DoubleMainWin->setMenuBar(menubar);
        statusbar = new QStatusBar(DoubleMainWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DoubleMainWin->setStatusBar(statusbar);

        retranslateUi(DoubleMainWin);

        QMetaObject::connectSlotsByName(DoubleMainWin);
    } // setupUi

    void retranslateUi(QMainWindow *DoubleMainWin)
    {
        DoubleMainWin->setWindowTitle(QCoreApplication::translate("DoubleMainWin", "Qlink-\345\217\214\344\272\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoubleMainWin: public Ui_DoubleMainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLEMAINWIN_H
