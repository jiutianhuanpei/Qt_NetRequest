#include "HBHttpWgt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HBHttpWgt w;
    w.show();
    return a.exec();
}
