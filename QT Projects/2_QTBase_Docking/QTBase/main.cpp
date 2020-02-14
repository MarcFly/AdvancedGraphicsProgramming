#include "dmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dmain w;
    w.show();

    return a.exec();
}
