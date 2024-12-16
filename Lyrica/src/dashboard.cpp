#include "lib/dashboard.h"
#include "ui_dashboard.h"

dashboard::dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dashboard)
{
    ui->setupUi(this);
    QPixmap card(":/images/assets/card.png");
    QPixmap backgroundPix(":/images/assets/dashboardBg.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
    QList<QLabel*> addCardList = { ui->set1, ui->set2 ,ui->set3, ui->set4 };
    QList<QLabel*> createCardList = { ui->customSet1, ui->customSet2 ,ui->customSet3, ui->customSet4 };

    for (QLabel* label : addCardList) {
        if (label) {
            label->setPixmap(card.scaled(300, 157, Qt::KeepAspectRatio));
        }
    }
    for (QLabel* label : createCardList) {
        if (label) {
            label->setPixmap(card.scaled(300, 157, Qt::KeepAspectRatio));
        }
    }
}

dashboard::~dashboard()
{
    delete ui;
}
