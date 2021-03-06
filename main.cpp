#include "micromouse.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Micromouse w;
    w.show();
    return a.exec();
}
