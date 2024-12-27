#include "lib/mainwindow.h"
#include "lib/setexplorer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SetExplorer w;
    w.show();
    return a.exec();
}
