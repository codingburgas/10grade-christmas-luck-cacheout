#ifndef SIGNINFORM_H
#define SIGNINFORM_H

#include <QDialog>
#include <QPixmap>


namespace Ui {
class signinForm;
}

class signinForm : public QDialog
{
    Q_OBJECT

public:
    explicit signinForm(QWidget *parent = nullptr);
    ~signinForm();

private:
    Ui::signinForm *ui;
};

#endif // SIGNINFORM_H
