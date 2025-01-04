#include "lib/cardcreation.h"
#include "ui_cardcreation.h"
#include<QDebug>

cardCreation::cardCreation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cardCreation)
{
    ui->setupUi(this);
    QPixmap backgroundPix(":/images/cardCreateBg.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
    numOfCards = 1;
    numOfTitles = 1;
}

void cardCreation::actionHandler(PageBools& pages){
    //Button Handling
    connect(ui->submitCard, &QPushButton::clicked, this, [this](){
        if(!ui->titleinput->text().isEmpty() && !ui->frontInput->text().isEmpty() && !ui->backinput->text().isEmpty()){ //Checks that the text boxes aren't empty
            cardCreation::submitClicked();
        }else ui->warning->setText("Input card details first!");
    });

    //Page Handling
    connect(ui->doneButton, &QPushButton::clicked, this, [&pages, this](){
        if(ui->frontInput->text().isEmpty() && ui->backinput->text().isEmpty()){ //Checks that the text boxes are empty
            cardCreation::doneClicked();
            pages.cardCreationShouldDisplay = false;
            pages.dashboardWindowShouldDisplay = true;
            emit pageStateChanged();
        } else ui->warning->setText("Submit card first!");
    });
}

void cardCreation::submitClicked()
{
    qDebug() << "Titles vector size:" << currentSet.titles.size();
    qDebug() << "Number of cards:" << numOfCards;

    if (static_cast<int>(currentSet.titles.size()) < numOfTitles) {
        currentSet.titles.resize(numOfTitles);
        qDebug() << "resized";
    }

    currentSet.titles[0].numCards += numOfCards;
    currentSet.numTitles += numOfTitles;

    currentSet.titles[numOfTitles - 1].cards.push_back(customCard());

    QString title = ui->titleinput->text();
    QString frontSideCurrent = ui->frontInput->text();
    QString backSideCurrent = ui->backinput->text();

    currentSet.titles[numOfTitles - 1].title = title.toStdString();
    currentSet.titles[numOfTitles - 1].cards[numOfCards - 1].frontSide = frontSideCurrent.toStdString();
    currentSet.titles[numOfTitles - 1].cards[numOfCards - 1].backSide = backSideCurrent.toStdString();

    std::cout << currentSet.titles[numOfTitles - 1].title << std::endl;
    std::cout << currentSet.titles[numOfTitles - 1].cards[numOfCards - 1].frontSide << std::endl;
    std::cout << currentSet.titles[numOfTitles - 1].cards[numOfCards - 1].backSide << std::endl;

    ui->frontInput->setText("");
    ui->backinput->setText("");

    numOfCards++;
    std::cout << numOfCards << std::endl;
}

void cardCreation::doneClicked(){
    cardCreation::cardCreationHandler();
    numOfTitles++;
    numOfCards = 1;
    ui->titleinput->setText("");

    qDebug() << "Done clicked";
    if (static_cast<int>(currentSet.titles.size()) < numOfTitles) {
        currentSet.titles.resize(numOfTitles);
        qDebug() << "resized";
    }

    if (numOfTitles < static_cast<int>(currentSet.titles.size())) {
        qDebug() << "Cards vector size:" << currentSet.titles[numOfTitles].cards.size();
    }
    qDebug() << "Titles vector size:" << currentSet.titles.size();
}

void cardCreation::cardCreationHandler(){
    int tempNumOfCards = 0;
    std::fstream customSetsFile;
    customSetsFile.open("../Lyrica/files/customSets.txt", std::ios::out | std::ios::app);
    if(!customSetsFile){
        std::cout << "customSets.txt failed to load!" << std::endl;
    }else{
        std::cout << "customSets.txt loaded successfully!" << std::endl;
        writeInFile(customSetsFile, currentSet.titles[numOfTitles - 1].title);
        for(int i = 1; i < numOfCards; i++){
            if(tempNumOfCards <= numOfCards){
                writeInFileMult(customSetsFile, currentSet.titles[numOfTitles - 1].cards[tempNumOfCards].frontSide, currentSet.titles[numOfTitles - 1].cards[tempNumOfCards].backSide);
                tempNumOfCards++;
            }else break;
        }
        customSetsFile << std::endl;
        std::cout << "Writing cards in file...";
        customSetsFile.close();
    }
}

cardCreation::~cardCreation()
{
    delete ui;
}
