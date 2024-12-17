#include "lib/mainwindow.h"
#include "lib/signinform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    signinForm w;
    w.show();
    return a.exec();
}
