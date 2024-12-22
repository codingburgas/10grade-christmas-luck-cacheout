#include "lib/app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App App;
    return a.exec();
}
