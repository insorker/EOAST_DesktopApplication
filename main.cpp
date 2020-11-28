#include "cthulhu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cthulhu w;
    w.show();
    return a.exec();
}
