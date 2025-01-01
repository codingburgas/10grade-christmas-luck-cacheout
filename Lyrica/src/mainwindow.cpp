#include "lib/mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::displayMainWindow();
}

void MainWindow::displayMainWindow(){
    //Loading the font
    int fontId = QFontDatabase::addApplicationFont(":/fonts/assets/SpaceGrotesk.ttf");
    if (fontId == -1) qDebug() << "Failed to load custom font.";
    else qDebug() << "Custom font loaded successfully:";
    QString fontSpaceGrotesk = QFontDatabase::applicationFontFamilies(fontId).at(0);


    //Loading the images
    QPixmap flashCardsPix(":/images/assets/mainCardsImg.png");
    ui->flashCardsImg->setPixmap(flashCardsPix.scaled(514, 463, Qt::KeepAspectRatio));

    QPixmap backgroundPix(":/images/assets/mainBackground.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
}

void MainWindow::actionHandler(PageBools& pages){
    //Page Handling
    connect(ui->getStartedBtn, &QPushButton::clicked, this, [&pages, this]() {
        pages.mainWindowShouldDisplay = false;
        pages.signUpWindowShouldDisplay = true;
        emit pageStateChanged();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
