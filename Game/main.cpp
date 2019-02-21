#include <QApplication>
#include "mytable.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QMainWindow w;
//    w.show();

    MyTable t;
    t.show();

    return a.exec();
}
