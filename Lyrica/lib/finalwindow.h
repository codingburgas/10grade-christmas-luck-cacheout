#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QDialog>
#include "lib/pageHandler.h"
#include "BLL/lib/readySets.h"
#include "BLL/lib/customset.h"

namespace Ui {
class finalwindow;
}

class finalwindow : public QDialog
{
    Q_OBJECT

public:
    explicit finalwindow(QWidget *parent = nullptr);
    ~finalwindow();
    void actionHandler(PageBools& pages);

signals:
    void pageStateChanged();

private:
    Ui::finalwindow *ui;
    void displayFinalWindow();
};

#endif // FINALWINDOW_H
