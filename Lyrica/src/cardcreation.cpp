#include "lib/cardcreation.h"
#include "ui_cardcreation.h"
#include<QDebug>

cardCreation::cardCreation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cardCreation)
{
    ui->setupUi(this);
    QPixmap backgroundPix(":/images/assets/cardCreateBg.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
    numOfCards = 1;
    numOfTitles = customSetsNS::customSets.titles.size();
    qDebug() << numOfTitles;

    customSetsNS::customSets.titles.resize(numOfTitles + 1);
}

void cardCreation::actionHandler(PageBools& pages){
    //Button Handling
    disconnect(ui->submitCard, &QPushButton::clicked, nullptr, nullptr);
    connect(ui->submitCard, &QPushButton::clicked, this, [this](){
        if(!ui->titleinput->text().isEmpty() && !ui->frontInput->text().isEmpty() && !ui->backinput->text().isEmpty()){ //Checks that the text boxes aren't empty
            cardCreation::submitClicked();
        }else ui->warning->setText("Input card details first!");
    });

    //Page Handling
    disconnect(ui->doneButton, &QPushButton::clicked, nullptr, nullptr);
    connect(ui->doneButton, &QPushButton::clicked, this, [&pages, this](){
        if(ui->frontInput->text().isEmpty() && ui->backinput->text().isEmpty()){ //Checks that the text boxes are empty
            qDebug() << "Done clicked and saved in file";
            pages.cardCreationShouldDisplay = false;
            qDebug() << "cardCreationShouldDisplay is now false";
            pages.dashboardWindowShouldDisplay = true;
            qDebug() << "dashboardWindowShouldDisplay is now true";
            emit pageStateChanged();
            qDebug() << "emitted";
        } else ui->warning->setText("Submit card first!");
    });


    connect(ui->doneButton, &QPushButton::clicked, this, [this](){
        if(ui->frontInput->text().isEmpty() && ui->backinput->text().isEmpty()){ //Checks that the text boxes are empty
            cardCreation::doneClicked();
        }
    });
}

void cardCreation::submitClicked()
{
    customSetsNS::customSets.titles[0].numCards = numOfCards;
    customSetsNS::customSets.numTitles = numOfTitles;

    qDebug() << "Number of cards1:" << customSetsNS::customSets.titles[customSetsNS::numTitles].cards.size();
    qDebug() << "Titles vector size:" << customSetsNS::customSets.titles.size();



    // Ensure cards vector is resized
    qDebug() << customSetsNS::customSets.titles[numOfTitles - 1].cards.size();
    qDebug() << numOfCards;
    if(customSetsNS::customSets.titles[numOfTitles - 1].cards.size() < numOfCards){
        qDebug() << "Resizing cards vector...";
        customSetsNS::customSets.titles[numOfTitles - 1].cards.resize(numOfCards + 1);
        qDebug() << "Resized!";
    }

    std::cout << "It gets to here" << std::endl;

    std::cout << "It gets to here" << std::endl;
    QString title = ui->titleinput->text();
    QString frontSideCurrent = ui->frontInput->text();
    QString backSideCurrent = ui->backinput->text();

    std::cout << "It gets to here" << std::endl;

    customSetsNS::customSets.titles[numOfTitles - 1].title = title.toStdString();
    std::cout << "Here too" << std::endl;
    customSetsNS::customSets.titles[numOfTitles - 1].cards[numOfCards - 1].frontSide = frontSideCurrent.toStdString();
    customSetsNS::customSets.titles[numOfTitles - 1].cards[numOfCards - 1].backSide = backSideCurrent.toStdString();

    std::cout << "Here too" << std::endl;
    std::cout << customSetsNS::customSets.titles[numOfTitles - 1].title << std::endl;
    std::cout << customSetsNS::customSets.titles[numOfTitles - 1].cards[numOfCards - 1].frontSide << std::endl;
    std::cout << customSetsNS::customSets.titles[numOfTitles - 1].cards[numOfCards - 1].backSide << std::endl;

    customSetsNS::customSets.titles[numOfTitles - 1].cards.push_back(newCard);
    ui->frontInput->setText("");
    ui->backinput->setText("");

    numOfCards++;
}

void cardCreation::doneClicked(){
    cardCreation::cardCreationHandler();

    customSetsNS::customSets.titles.push_back(newSet);

    numOfTitles++;
    customSetsNS::numTitles++;
    customSetsNS::customSets.numTitles = customSetsNS::numTitles;

    qDebug() << "Done clicked";
    qDebug() << "Vector number of titles: " << customSetsNS::customSets.numTitles;
    qDebug() << "Titles vector size:" << customSetsNS::customSets.titles.size();

    ui->titleinput->setText("");

    if (numOfTitles - 1 > customSetsNS::customSets.titles.size()) {
        customSetsNS::customSets.titles.resize(numOfTitles);
        qDebug() << "Resized titles vector to size: " << customSetsNS::customSets.titles.size();
    }

    if (numOfTitles < static_cast<int>(customSetsNS::customSets.titles.size())) {
        qDebug() << "Cards vector size:" << customSetsNS::customSets.titles[numOfTitles - 1].cards.size();
    }

    numOfCards = 1;
}

void cardCreation::cardCreationHandler(){
    int tempNumOfCards = 0;
    std::fstream customSetsFile;
    customSetsFile.open("../Lyrica/files/customSets.txt", std::ios::out | std::ios::app);
    if(!customSetsFile){
        std::cout << "customSets.txt failed to load!" << std::endl;
    }else{
        std::cout << "customSets.txt loaded successfully!" << std::endl;
        writeInFile(customSetsFile, customSetsNS::customSets.titles[numOfTitles - 1].title);
        for(int i = 1; i < numOfCards; i++){
            if(tempNumOfCards <= numOfCards){
                writeInFileMult(customSetsFile, customSetsNS::customSets.titles[numOfTitles - 1].cards[tempNumOfCards].frontSide, customSetsNS::customSets.titles[numOfTitles - 1].cards[tempNumOfCards].backSide);
                tempNumOfCards++;
            }else break;
        }
        customSetsFile << std::endl;
        std::cout << "Writing cards in file..." << std::endl;
        customSetsFile.close();
    }
}

cardCreation::~cardCreation()
{
    delete ui;
}
