#include "lib/signinform.h"
#include "ui_signinform.h"

signinForm::signinForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signinForm)
{
    ui->setupUi(this);
    QPixmap backgroundPix(":/images/assets/signinBackground.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
}

signinForm::~signinForm()
{
    delete ui;
}
