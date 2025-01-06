#include "../lib/finalwindow.h"
#include "ui_finalwindow.h"

finalwindow::finalwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::finalwindow)
{
    ui->setupUi(this);

    finalwindow::displayFinalWindow();
}

void finalwindow::displayFinalWindow(){
    QPixmap backgroundPix(":/images/assets/mainBackground.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
}

void finalwindow::actionHandler(PageBools& pages){
    //Page Handling

    connect(ui->restartButton, &QPushButton::clicked, this, [&pages, this](){
        pages.finalWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->returnButton, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::active = false;
        customSetsNS::active = false;
        pages.finalWindowShouldDisplay = false;
        pages.dashboardWindowShouldDisplay = true;
        emit pageStateChanged();
    });
}

finalwindow::~finalwindow()
{
    delete ui;
}
