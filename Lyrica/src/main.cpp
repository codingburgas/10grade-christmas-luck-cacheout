#include "lib/mainwindow.h"
#include "lib/signupform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    signupForm w;
    w.show();
    w.actionHandler();
    return a.exec();
}
