#include "qtandyrec.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtAndyRec w;
    w.show();
    return a.exec();
}
