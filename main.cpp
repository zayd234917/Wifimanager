#include "wifimanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wifimanager w;
    w.show();
    return a.exec();
}
