#ifndef SIGNINFORM_H
#define SIGNINFORM_H

#include <QDialog>
#include <QPixmap>
#include "BLL/lib/signin.h"
#include "BLL/lib/credentials.h"
#include "DAL/lib/files.h"
#include "lib/pageHandler.h"

namespace Ui {
class signinForm;
}

class signinForm : public QDialog
{
    Q_OBJECT

public:
    explicit signinForm(QWidget *parent = nullptr);
    void actionHandler(PageBools& pages);
    ~signinForm();

signals:
    void pageStateChanged();

private:
    Ui::signinForm *ui;
    void displaySignIn();
    void textBoxHandler();
    bool signInHandler();
};

#endif // SIGNINFORM_H
