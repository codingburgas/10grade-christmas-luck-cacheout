#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class signupForm;
}

class signupForm : public QDialog
{
    Q_OBJECT

public:
    explicit signupForm(QWidget *parent = nullptr);
    ~signupForm();

private:
    Ui::signupForm *ui;
};

#endif // SIGNUPFORM_H
