#include "lib/setexplorer.h"
#include "ui_setexplorer.h"

SetExplorer::SetExplorer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SetExplorer)
{
    ui->setupUi(this);
    QPixmap card(":/images/assets/card.png");
    QPixmap backgroundPix(":/images/assets/dashboardBg.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
    QList<QLabel*> addCardList = { ui->set1, ui->set2 ,ui->set3, ui->set4, ui->set5, ui->set6, ui->set7, ui->set8, ui->set9, ui->set10, ui->set11, ui->set12 };

    for (QLabel* label : addCardList) {
        if (label) {
            label->setPixmap(card.scaled(300, 157, Qt::KeepAspectRatio));
        }
    }


}

SetExplorer::~SetExplorer()
{
    delete ui;
}
