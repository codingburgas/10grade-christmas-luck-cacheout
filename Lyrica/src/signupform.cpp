#include "lib/signupform.h"
#include "ui_signupform.h"

signupForm::signupForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signupForm)
{
    ui->setupUi(this);
    QPixmap backgroundPix(":/images/assets/registerBackground.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
}

signupForm::~signupForm()
{
    delete ui;
}
