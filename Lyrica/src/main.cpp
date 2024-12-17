#include "lib/practicewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PracticeWindow w;
    w.show();
    return a.exec();
}
