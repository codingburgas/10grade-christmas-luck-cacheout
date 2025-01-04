#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontDatabase>
#include <QPixmap>
#include "DAL/lib/files.h"
#include "BLL/lib/readySets.h"
#include "BLL/lib/customset.h"
#include "lib/pageHandler.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void actionHandler(PageBools& pages);
    ~MainWindow();

signals:
    void pageStateChanged();

private:
    Ui::MainWindow *ui;
    void displayMainWindow();
    void getReadySetsFromFile();
    void getCustomSetsFromFile();

    readySet readySet;
    customSet customSet;
    int numOfCards;
};
#endif // MAINWINDOW_H
