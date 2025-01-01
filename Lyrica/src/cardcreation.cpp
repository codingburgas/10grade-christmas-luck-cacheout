#include "lib/cardcreation.h"
#include "ui_cardcreation.h"

cardCreation::cardCreation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cardCreation)
{
    ui->setupUi(this);
    QPixmap backgroundPix(":/images/cardCreateBg.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
}

cardCreation::~cardCreation()
{
    delete ui;
}
