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
    // Button Handling
    disconnect(ui->submitCard, &QPushButton::clicked, nullptr, nullptr);
    connect(ui->submitCard, &QPushButton::clicked, this, [this](){
        if(!ui->titleinput->text().isEmpty() && !ui->frontInput->text().isEmpty() && !ui->backinput->text().isEmpty()){     // Check that the text boxes aren't empty
            cardCreation::submitClicked();
        }else ui->warning->setText("Input card details first!");
    });

    // Page Handling
    disconnect(ui->doneButton, &QPushButton::clicked, nullptr, nullptr);
    connect(ui->doneButton, &QPushButton::clicked, this, [&pages, this](){
        if(ui->frontInput->text().isEmpty() && ui->backinput->text().isEmpty()){    // Check that the text boxes are empty
            pages.cardCreationShouldDisplay = false;
            pages.dashboardWindowShouldDisplay = true;
            emit pageStateChanged();
        } else ui->warning->setText("Submit card first!");
    });


    connect(ui->doneButton, &QPushButton::clicked, this, [this](){
        if(ui->frontInput->text().isEmpty() && ui->backinput->text().isEmpty()){    // Check that the text boxes are empty
            cardCreation::doneClicked();
        }
    });
}

void cardCreation::submitClicked()
{
    customSetsNS::customSets.titles[0].numCards = numOfCards;
    customSetsNS::customSets.numTitles = numOfTitles;


    if(customSetsNS::customSets.titles[numOfTitles - 1].cards.size() < numOfCards){     // Ensure the cards vector is the right size and if not resize it
        customSetsNS::customSets.titles[numOfTitles - 1].cards.resize(numOfCards + 1);
    }

    QString title = ui->titleinput->text();
    QString frontSideCurrent = ui->frontInput->text();
    QString backSideCurrent = ui->backinput->text();

    // Set the vector card variables
    customSetsNS::customSets.titles[numOfTitles - 1].title = title.toStdString();
    customSetsNS::customSets.titles[numOfTitles - 1].cards[numOfCards - 1].frontSide = frontSideCurrent.toStdString();
    customSetsNS::customSets.titles[numOfTitles - 1].cards[numOfCards - 1].backSide = backSideCurrent.toStdString();

    // Show the title and the cards just entered in the application output
    std::cout << customSetsNS::customSets.titles[numOfTitles - 1].title << std::endl;
    std::cout << customSetsNS::customSets.titles[numOfTitles - 1].cards[numOfCards - 1].frontSide << std::endl;
    std::cout << customSetsNS::customSets.titles[numOfTitles - 1].cards[numOfCards - 1].backSide << std::endl;

    // Update cards vector
    customSetsNS::customSets.titles[numOfTitles - 1].cards.push_back(newCard);

    // Empty card front side and back side text boxes
    ui->frontInput->setText("");
    ui->backinput->setText("");

    // Move onto the next card
    numOfCards++;
    customSetsNS::customSets.titles[numOfTitles - 1].numCards++;
}

void cardCreation::doneClicked(){
    if(!customSetsNS::customSets.titles[numOfTitles - 1].title.empty())     // Only write in file if the card is not empty
        cardCreation::cardCreationHandler();

    // Update titles vector
    customSetsNS::customSets.titles.push_back(newSet);

    // Move onto the next title
    numOfTitles++;
    customSetsNS::numTitles++;
    customSetsNS::customSets.numTitles++;

    // Empty sets title text box
    ui->titleinput->setText("");

    if (numOfTitles - 1 > customSetsNS::customSets.titles.size()) {     // Check if titles vector is the right size and if not resize it
        customSetsNS::customSets.titles.resize(numOfTitles);
    }

    // Reset card counter for next use
    numOfCards = 1;
}

void cardCreation::cardCreationHandler(){
    int tempNumOfCards = 0;
    std::fstream customSetsFile;
    customSetsFile.open("../Lyrica/files/customSets.txt", std::ios::out | std::ios::app);
    if(!customSetsFile){    // Check if file opened correctly
        std::cout << "customSets.txt failed to load!" << std::endl;
    }else{
        std::cout << "customSets.txt loaded successfully!" << std::endl;
        writeInFile(customSetsFile, customSetsNS::customSets.titles[numOfTitles - 1].title);    // Input the set title in file
        for(int i = 1; i < numOfCards; i++){
            if(tempNumOfCards <= numOfCards){
                // Input the sets cards in file
                writeInFileMult(customSetsFile, customSetsNS::customSets.titles[numOfTitles - 1].cards[tempNumOfCards].frontSide, customSetsNS::customSets.titles[numOfTitles - 1].cards[tempNumOfCards].backSide);
                tempNumOfCards++;
            }else break;
        }
        customSetsFile << std::endl;    // Input extra line after set
        std::cout << "Writing cards in file..." << std::endl;
        customSetsFile.close();
    }
}

cardCreation::~cardCreation()
{
    delete ui;
}
