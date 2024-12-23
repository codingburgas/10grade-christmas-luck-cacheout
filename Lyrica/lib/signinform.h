#ifndef SIGNINFORM_H
#define SIGNINFORM_H

#include <QDialog>
#include <QPixmap>
#include "BLL/lib/signin.h"
#include "BLL/lib/credentials.h"
#include "DAL/lib/files.h"

namespace Ui {
class signinForm;
}

class signinForm : public QDialog
{
    Q_OBJECT

public:
    explicit signinForm(QWidget *parent = nullptr);
    void textBoxHandler();
    void actionHandler();
    bool signInHandler();
    ~signinForm();

private:
    Ui::signinForm *ui;
};

#endif // SIGNINFORM_H
