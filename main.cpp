#include "openmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenMenu w;
    w.show();
    return a.exec();
}
