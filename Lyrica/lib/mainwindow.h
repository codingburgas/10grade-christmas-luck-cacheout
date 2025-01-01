#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontDatabase>
#include <QPixmap>
#include "../lib/pageHandler.h"

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

};
#endif // MAINWINDOW_H
