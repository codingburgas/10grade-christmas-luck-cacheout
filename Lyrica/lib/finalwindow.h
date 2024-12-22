#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QDialog>

namespace Ui {
class finalwindow;
}

class finalwindow : public QDialog
{
    Q_OBJECT

public:
    explicit finalwindow(QWidget *parent = nullptr);
    ~finalwindow();

private:
    Ui::finalwindow *ui;
};

#endif // FINALWINDOW_H
