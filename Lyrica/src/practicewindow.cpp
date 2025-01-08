#include "lib/practicewindow.h"
#include "ui_practicewindow.h"

PracticeWindow::PracticeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PracticeWindow)
{
    ui->setupUi(this);

    PracticeWindow::DisplayPracticeWindow();
    finalCard = false;
}


void PracticeWindow::DisplayPracticeWindow(){
    // Load the custom font
    int fontId = QFontDatabase::addApplicationFont(":/fonts/assets/SpaceGrotesk.ttf");
    if (fontId == -1)
        qDebug() << "Failed to load custom font.";
    else
        qDebug() << "Custom font loaded successfully";
    QString fontSpaceGrotesk = QFontDatabase::applicationFontFamilies(fontId).at(0);


    // Load the images
    QPixmap backgroundPix(":/images/assets/mainBackground.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));

    // Set the flashCard button icon
    QPixmap flashCardPix(":/images/assets/flashCard.png");
    QIcon buttonIcon(flashCardPix);
    ui->flashCard->setPixmap(flashCardPix.scaled(418, 224, Qt::KeepAspectRatio));

    ui->flashCardTextBox->raise();
    ui->flashCardTextBox->setAttribute(Qt::WA_TransparentForMouseEvents); // Make the text to not disturb the flashCard hover effect
}


void PracticeWindow::actionHandler(PageBools& pages){
    static bool processing = false; // Guard flag to prevent recursive calls

    if (processing) {
        return;
    }
    processing = true;


    // Display only the active set
    if (readySetsNS::active) {
        displayReadySet();
    }

    if (customSetsNS::active) {
        displayCustomSet();
    }


    // Know Button Handling and Final Card Handling
    disconnect(ui->knowTextBox, &QPushButton::clicked, nullptr, nullptr);
    connect(ui->knowTextBox, &QPushButton::clicked, this, [this]() {
        if(!finalCard){
            readySetsNS::knowAnswer = true;
            customSetsNS::knowAnswer = true;
            readySetsNS::numCards++;
            customSetsNS::numCards++;
            if (readySetsNS::active) {
                displayReadySet(); // Refresh UI for ready set
            }
            if (customSetsNS::active) {
                displayCustomSet(); // Refresh UI for custom set
            }
        }

        if(finalCard){
            readySetsNS::knowAnswer = true;
            customSetsNS::knowAnswer = true;

            if (readySetsNS::active) {
                displayReadySet(); // Refresh UI for ready set
            }
            if (customSetsNS::active) {
                displayCustomSet(); // Refresh UI for custom set
            }
        }
    });


    // Don't Know Button Handling
    disconnect(ui->dontKnowTextBox, &QPushButton::clicked, nullptr, nullptr);
    connect(ui->dontKnowTextBox, &QPushButton::clicked, this, [this]() {
        readySetsNS::knowAnswer = false;
        customSetsNS::knowAnswer = false;
        if (readySetsNS::active) {
            displayReadySet(); // Refresh UI for ready set
        }
        if (customSetsNS::active) {
            displayCustomSet(); // Refresh UI for custom set
        }
        emit pageStateChanged();
    });


    // Back Button Handling
    disconnect(ui->backArrow, &QPushButton::clicked, nullptr, nullptr);
    connect(ui->backArrow, &QPushButton::clicked, this, [&pages, this]() {
        readySetsNS::knowAnswer = true;
        customSetsNS::knowAnswer = true;
        readySetsNS::numCards = 0;
        customSetsNS::numCards = 0;
        finalCard = false;
        if (readySetsNS::active) {
            displayReadySet(); // Refresh UI for ready set
        }
        if (customSetsNS::active) {
            displayCustomSet(); // Refresh UI for custom set
        }
        readySetsNS::active = false;
        customSetsNS::active = false;
        pages.practiceWindowShouldDisplay = false;
        pages.dashboardWindowShouldDisplay = true;
        emit pageStateChanged();
    });


    // Finish Set Button Handling
    disconnect(ui->finishTextBox, &QPushButton::clicked, nullptr, nullptr);
    connect(ui->finishTextBox, &QPushButton::clicked, this, [&pages, this]() {
        if(finalCard){
            readySetsNS::knowAnswer = true;
            customSetsNS::knowAnswer = true;
            readySetsNS::numCards = 0;
            customSetsNS::numCards = 0;
            finalCard = false;
            if (readySetsNS::active) {
                displayReadySet();
            }

            if (customSetsNS::active) {
                displayCustomSet();
            }
            pages.practiceWindowShouldDisplay = false;
            pages.finalWindowShouldDisplay = true;
            emit pageStateChanged();
        }
    });

    processing = false; // Reset the guard
}


void PracticeWindow::displayReadySet(){
    QString title = QString::fromStdString(readySetsNS::readySets.titles[readySetsNS::numTitles].title);
    QString cardFront = QString::fromStdString(readySetsNS::readySets.titles[readySetsNS::numTitles].cards[readySetsNS::numCards].frontSide);
    QString cardBack = QString::fromStdString(readySetsNS::readySets.titles[readySetsNS::numTitles].cards[readySetsNS::numCards].backSide);

    ui->titleTextBox->setText(title);
    if(readySetsNS::knowAnswer)
        ui->flashCardTextBox->setText(cardFront);
    else    // Show backSide if frontSide is not known
        ui->flashCardTextBox->setText(cardBack);

    // Check if the last card has been reached
    if (readySetsNS::numCards == readySetsNS::readySets.titles[readySetsNS::numTitles].cards.size() - 1) {
        finalCard = true;
        readySetsNS::numCards = readySetsNS::readySets.titles[readySetsNS::numTitles].cards.size() - 1;
        qDebug() << "No more cards in readySets!";
    }

    ui->finishTextBox->setVisible(finalCard);
    ui->meaning->setVisible(!readySetsNS::knowAnswer);
}


void PracticeWindow::displayCustomSet(){
    QString title = QString::fromStdString(customSetsNS::customSets.titles[customSetsNS::numTitles].title);
    QString cardFront = QString::fromStdString(customSetsNS::customSets.titles[customSetsNS::numTitles].cards[customSetsNS::numCards].frontSide);
    QString cardBack = QString::fromStdString(customSetsNS::customSets.titles[customSetsNS::numTitles].cards[customSetsNS::numCards].backSide);

    ui->titleTextBox->setText(title);
    if(customSetsNS::knowAnswer)
        ui->flashCardTextBox->setText(cardFront);
    else    // Show backSide if frontSide is not known
        ui->flashCardTextBox->setText(cardBack);

    // Check if the last card has been reached
    if (customSetsNS::customSets.titles[customSetsNS::numTitles].cards[customSetsNS::numCards].frontSide.empty()) {
        finalCard = true;
        customSetsNS::numCards = customSetsNS::customSets.titles[customSetsNS::numTitles].cards.size() - 3;
        qDebug() << "No more cards in customSets!";
    }

    ui->finishTextBox->setVisible(finalCard);
    ui->meaning->setVisible(!customSetsNS::knowAnswer);
}


PracticeWindow::~PracticeWindow()
{
    delete ui;
}
