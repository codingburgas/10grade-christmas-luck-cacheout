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
    connect(ui->backButton, &QPushButton::clicked, this, [&pages, this](){
        pages.finalWindowShouldDisplay = false;
        pages.dashboardWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->restartButton, &QPushButton::clicked, this, [&pages, this](){
        pages.finalWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->tryButton, &QPushButton::clicked, this, [&pages, this](){
        pages.finalWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });
}

finalwindow::~finalwindow()
{
    delete ui;
}
