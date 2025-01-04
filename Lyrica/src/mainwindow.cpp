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
    numOfCards = readySet.titles[readySet.numTitles].numCards;
    readySet.titles[readySet.numTitles].cards.resize(numOfCards + 1);
    std::cout << "Vector Size: " << readySet.titles[readySet.numTitles].cards.size() << std::endl;

    std::fstream readySetsFile;
    readySetsFile.open("../Lyrica/files/readySets.txt", std::ios::in | std::ios::out | std::ios::app);

    if(!readySetsFile){
        std::cout << "readySets.txt failed to load!" << std::endl;
    }else{
        std::cout << "readySets.txt loaded successfully!" << std::endl;
        getFromFileReady(readySetsFile,
                    readySet.titles,
                    readySet.numTitles,
                    readySet.titles[readySet.numTitles].numCards);
        readySetsFile.close();

    }
    std::cout << "Vector Size: " << readySet.titles[readySet.numTitles].cards.size() << std::endl;
    std::cout << "Title: " << readySet.titles[readySet.numTitles].title << std::endl;
    std::cout << readySet.numTitles << std::endl;
    std::cout << readySet.titles[readySet.numTitles].numCards << std::endl;
}

void MainWindow::getCustomSetsFromFile(){
    numOfCards = customSet.titles[customSet.numTitles].numCards;
    customSet.titles[customSet.numTitles].cards.resize(numOfCards + 1);

    std::cout << "Vector Size: " << customSet.titles[customSet.numTitles].cards.size() << std::endl;
    std::fstream customSetsFile;
    customSetsFile.open("../Lyrica/files/customSets.txt", std::ios::in | std::ios::out | std::ios::app);

    if(!customSetsFile){
        std::cout << "customSets.txt failed to load!" << std::endl;
    }else{
        std::cout << "customSets.txt loaded successfully!" << std::endl;

        getFromFileCustom(customSetsFile,
                          customSet.titles,
                          customSet.numTitles,
                          customSet.titles[customSet.numTitles].numCards);
        customSetsFile.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
