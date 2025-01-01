#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QDialog>
#include <QPixmap>
#include "BLL/lib/signup.h"
#include "DAL/lib/files.h"
#include "BLL/lib/credentials.h"
#include "lib/pageHandler.h"

namespace Ui {
class signupForm;
}

class signupForm : public QDialog
{
    Q_OBJECT

public:
    explicit signupForm(QWidget *parent = nullptr);
    void actionHandler(PageBools& pages);
    ~signupForm();

signals:
    void pageStateChanged();

private:
    Ui::signupForm *ui;
    void displaySignUp();
    void textBoxHandler();
    bool signUpHandler();
};

#endif // SIGNUPFORM_H
