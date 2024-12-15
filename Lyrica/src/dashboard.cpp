#include "lib/dashboard.h"
#include "ui_dashboard.h"

dashboard::dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dashboard)
{
    ui->setupUi(this);

    QPixmap backgroundPix(":/images/assets/dashboardBg.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
}

dashboard::~dashboard()
{
    delete ui;
}
