#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QDialog>
#include <QPixmap>
#include "BLL/lib/signup.h"
#include "DAL/lib/files.h"
#include "BLL/lib/credentials.h"

namespace Ui {
class signupForm;
}

class signupForm : public QDialog
{
    Q_OBJECT

public:
    explicit signupForm(QWidget *parent = nullptr);
    void textBoxHandler();
    void actionHandler();
    bool signUpHandler();
    ~signupForm();

private:
    Ui::signupForm *ui;
};

#endif // SIGNUPFORM_H
