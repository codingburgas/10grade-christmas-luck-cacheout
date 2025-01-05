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
        MainWindow::getReadySetsFromFile();
        MainWindow::getCustomSetsFromFile();
        pages.mainWindowShouldDisplay = false;
        pages.signUpWindowShouldDisplay = true;
        emit pageStateChanged();
    });
}

void MainWindow::getReadySetsFromFile(){
    numOfCards = readySetsNS::readySets.titles[readySetsNS::readySets.numTitles].numCards;
    readySetsNS::readySets.titles[readySetsNS::readySets.numTitles].cards.resize(numOfCards + 1);
    std::cout << "Vector Size: " << readySetsNS::readySets.titles[readySetsNS::readySets.numTitles].cards.size() << std::endl;

    std::fstream readySetsFile;
    readySetsFile.open("../Lyrica/files/readySets.txt", std::ios::in | std::ios::out | std::ios::app);

    if(!readySetsFile){
        std::cout << "readySets.txt failed to load!" << std::endl;
    }else{
        std::cout << "readySets.txt loaded successfully!" << std::endl;
        getFromFileReady(readySetsFile,
                    readySetsNS::readySets.titles,
                    readySetsNS::readySets.numTitles,
                    readySetsNS::readySets.titles[readySetsNS::readySets.numTitles].numCards);
        readySetsFile.close();

    }
    std::cout << "Vector Size: " << readySetsNS::readySets.titles[readySetsNS::readySets.numTitles].cards.size() << std::endl;
    std::cout << "Title: " << readySetsNS::readySets.titles[readySetsNS::readySets.numTitles].title << std::endl;
    std::cout << readySetsNS::readySets.numTitles << std::endl;
    std::cout << readySetsNS::readySets.titles[readySetsNS::readySets.numTitles].numCards << std::endl;
}

void MainWindow::getCustomSetsFromFile(){
    numOfCards = customSetsNS::customSets.titles[customSetsNS::customSets.numTitles].numCards;
    customSetsNS::customSets.titles[customSetsNS::customSets.numTitles].cards.resize(numOfCards + 1);

    std::cout << "Vector Size: " << customSetsNS::customSets.titles[customSetsNS::customSets.numTitles].cards.size() << std::endl;
    std::fstream customSetsFile;
    customSetsFile.open("../Lyrica/files/customSets.txt", std::ios::in | std::ios::out | std::ios::app);

    if(!customSetsFile){
        std::cout << "customSets.txt failed to load!" << std::endl;
    }else{
        std::cout << "customSets.txt loaded successfully!" << std::endl;

        getFromFileCustom(customSetsFile,
                          customSetsNS::customSets.titles,
                          customSetsNS::customSets.numTitles,
                          customSetsNS::customSets.titles[customSetsNS::customSets.numTitles].numCards);
        customSetsFile.close();

        std::cout << "Last custom set number of cards " << customSetsNS::customSets.titles[customSetsNS::customSets.numTitles].cards.size() << std::endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
