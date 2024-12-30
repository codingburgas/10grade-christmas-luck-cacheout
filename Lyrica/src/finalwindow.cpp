#include "finalwindow.h"
#include "ui_finalwindow.h"

finalwindow::finalwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::finalwindow)
{
    ui->setupUi(this);
    QPixmap backgroundPix(":/images/assets/mainBackground.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
}

finalwindow::~finalwindow()
{
    delete ui;
}
