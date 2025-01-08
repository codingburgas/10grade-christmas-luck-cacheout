#include "lib/dashboard.h"
#include "ui_dashboard.h"
#include <QPushButton>
#include <QEvent>

dashboard::dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dashboard)
{
    ui->setupUi(this);

    numOfSets = 0;
}


void dashboard::displayDashboard(){

    QPixmap backgroundPix(":/images/assets/dashboardBg.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));

    QString dashUsername = QString::fromStdString(credentials::username);
    ui->username->setText(dashUsername + "!");

}


void dashboard::actionHandler(PageBools& pages){
    dashboard::displayDashboard();
    displayCustomSets(1);
    displayReadySets(1);


    //Page Handling
    connect(ui->signOutButton, &QPushButton::clicked, this, [&pages, this](){
        pages.dashboardWindowShouldDisplay = false;
        pages.mainWindowShouldDisplay = true;
        credentials::username = "";
        credentials::email = "";
        credentials::password = "";
        emit pageStateChanged();
    });

    connect(ui->addNewSet, &QPushButton::clicked, this, [&pages, this](){
        pages.dashboardWindowShouldDisplay = false;
        pages.setExplorerWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->createNewSet, &QPushButton::clicked, this, [&pages, this](){
        pages.dashboardWindowShouldDisplay = false;
        pages.cardCreationShouldDisplay = true;
        emit pageStateChanged();
    });


    //Ready Sets Handling
    connect(ui->set1, &QPushButton::clicked, this, [&pages, this](){
        if(setsGroup1){
            readySetsNS::numTitles = 1;
            readySetsNS::active = true;
        }else if(setsGroup2){
            readySetsNS::numTitles = 5;
            readySetsNS::active = true;
        }else if(setsGroup3){
            readySetsNS::numTitles = 9;
            readySetsNS::active = true;
        }
        pages.dashboardWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set2, &QPushButton::clicked, this, [&pages, this](){
        if(setsGroup1){
            readySetsNS::numTitles = 2;
            readySetsNS::active = true;
        }else if(setsGroup2){
            readySetsNS::numTitles = 6;
            readySetsNS::active = true;
        }else if(setsGroup3){
            readySetsNS::numTitles = 10;
            readySetsNS::active = true;
        }
        pages.dashboardWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set3, &QPushButton::clicked, this, [&pages, this](){
        if(setsGroup1){
            readySetsNS::numTitles = 3;
            readySetsNS::active = true;
        }else if(setsGroup2){
            readySetsNS::numTitles = 7;
            readySetsNS::active = true;
        }else if(setsGroup3){
            readySetsNS::numTitles = 11;
            readySetsNS::active = true;
        }
        pages.dashboardWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set4, &QPushButton::clicked, this, [&pages, this](){
        if(setsGroup1){
            readySetsNS::numTitles = 4;
            readySetsNS::active = true;
        }else if(setsGroup2){
            readySetsNS::numTitles = 8;
            readySetsNS::active = true;
        }else if(setsGroup3){
            readySetsNS::numTitles = 12;
            readySetsNS::active = true;
        }
        pages.dashboardWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });



    //Custom Sets Handling
    disconnect(ui->customSet1, &QPushButton::clicked, nullptr, nullptr);
    connect(ui->customSet1, &QPushButton::clicked, this, [&pages, this](){
        if(setsGroup1){
            customSetsNS::numTitles = 1;
            customSetsNS::active = true;
        }else if(setsGroup2 && customSetsNS::customSets.titles.size() <= 5){
            customSetsNS::numTitles = 5;
            customSetsNS::active = true;
        }else if(setsGroup3 && customSetsNS::customSets.titles.size() <= 9){
            customSetsNS::numTitles = 9;
            customSetsNS::active = true;
        }
        pages.dashboardWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    disconnect(ui->customSet2, &QPushButton::clicked, nullptr, nullptr);
    connect(ui->customSet2, &QPushButton::clicked, this, [&pages, this](){
        if(setsGroup1){
            customSetsNS::numTitles = 2;
            customSetsNS::active = true;
        }else if(setsGroup2 && customSetsNS::customSets.titles.size() <= 6){
            customSetsNS::numTitles = 6;
            customSetsNS::active = true;
        }else if(setsGroup3 && customSetsNS::customSets.titles.size() <= 10){
            customSetsNS::numTitles = 10;
            customSetsNS::active = true;
        }
        pages.dashboardWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    disconnect(ui->customSet3, &QPushButton::clicked, nullptr, nullptr);
    connect(ui->customSet3, &QPushButton::clicked, this, [&pages, this](){
        if(setsGroup1){
            customSetsNS::numTitles = 3;
            customSetsNS::active = true;
        }else if(setsGroup2 && customSetsNS::customSets.titles.size() <= 7){
            customSetsNS::numTitles = 7;
            customSetsNS::active = true;
        }else if(setsGroup3 && customSetsNS::customSets.titles.size() <= 11){
            customSetsNS::numTitles = 11;
            customSetsNS::active = true;
        }
        pages.dashboardWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    disconnect(ui->customSet4, &QPushButton::clicked, nullptr, nullptr);
    connect(ui->customSet4, &QPushButton::clicked, this, [&pages, this](){
        if(setsGroup1){
            customSetsNS::numTitles = 4;
            customSetsNS::active = true;
        }else if(setsGroup2 && customSetsNS::customSets.titles.size() <= 8){
            customSetsNS::numTitles = 8;
            customSetsNS::active = true;
        }else if(setsGroup3 && customSetsNS::customSets.titles.size() <= 12){
            customSetsNS::numTitles = 12;
            customSetsNS::active = true;
        }
        pages.dashboardWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });


    // Arrows for ready sets
    connect(ui->rightArrowSets, &QPushButton::clicked, this, [this]() {
        if (setsGroup1) {
            displayReadySets(5);
            setsGroup1 = false;
            setsGroup2 = true;
        } else if (setsGroup2) {
            displayReadySets(9);
            setsGroup2 = false;
            setsGroup3 = true;
        }
    });

    connect(ui->leftArrowSets, &QPushButton::clicked, this, [this]() {
        if (setsGroup2) {
            displayReadySets(1);
            setsGroup2 = false;
            setsGroup1 = true;
        } else if (setsGroup3) {
            displayReadySets(5);
            setsGroup3 = false;
            setsGroup2 = true;
        }
    });


    // Arrows for custom sets
    connect(ui->rightArrowCustom, &QPushButton::clicked, this, [this]() {
        if (customSetsGroup1) {
            displayCustomSets(5);
            customSetsGroup1 = false;
            customSetsGroup2 = true;
        } else if (customSetsGroup2) {
            displayCustomSets(9);
            customSetsGroup2 = false;
            customSetsGroup3 = true;
        }
    });

    connect(ui->leftArrowCustom, &QPushButton::clicked, this, [this]() {
        if (customSetsGroup2) {
            displayCustomSets(1);
            customSetsGroup2 = false;
            customSetsGroup1 = true;
        } else if (customSetsGroup3) {
            displayCustomSets(5);
            customSetsGroup3 = false;
            customSetsGroup2 = true;
        }
    });

}


void dashboard::displayReadySets(int cardNum){
    QPixmap card(":/images/assets/card.png");
    QList<QPushButton*> CardList = { ui->set1, ui->set2 ,ui->set3, ui->set4};

    for (QPushButton* button : CardList) {      // Set the same properties on all cards
        if (button) {
            QIcon buttonIcon(card);
            button->setIcon(buttonIcon);
            button->setIconSize(QSize(300, 157));
            button->installEventFilter(this);
        }
    }

    // Set the respective set title on each card in order
    ui->setTitle1->setText(QString::fromStdString(readySetsNS::readySets.titles[cardNum].title));
    ui->setTitle1->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->setTitle2->setText(QString::fromStdString(readySetsNS::readySets.titles[cardNum + 1].title));
    ui->setTitle2->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->setTitle3->setText(QString::fromStdString(readySetsNS::readySets.titles[cardNum + 2].title));
    ui->setTitle3->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->setTitle4->setText(QString::fromStdString(readySetsNS::readySets.titles[cardNum + 3].title));
    ui->setTitle4->setAttribute(Qt::WA_TransparentForMouseEvents);
}


void  dashboard::displayCustomSets(int cardNum){
    QPixmap card(":/images/assets/card.png");
    QIcon buttonIcon(card);
    numOfSets = customSetsNS::customSets.numTitles;

    // Show the custom sets and sets their title if they exist
    if(numOfSets >= cardNum ){
        if(!customSetsNS::customSets.titles[cardNum].title.empty() && !(customSetsNS::customSets.titles[cardNum].title == " ")){    // Check if there's any information on the card in the vector
            ui->customSetTitle1->setText(QString::fromStdString(customSetsNS::customSets.titles[cardNum].title));
            ui->customSetTitle1->setAttribute(Qt::WA_TransparentForMouseEvents);
            ui->customSet1->setIcon(buttonIcon);
            ui->customSet1->setIconSize(QSize(300, 157));
            ui->customSet1->installEventFilter(this);
            customSetsExist = true;
        }
    }
    if(numOfSets >= cardNum + 1){
        if(!customSetsNS::customSets.titles[cardNum + 1].title.empty() && !(customSetsNS::customSets.titles[cardNum + 1].title == " ")){    // Check if there's any information on the card in the vector
            ui->customSetTitle2->setText(QString::fromStdString(customSetsNS::customSets.titles[cardNum + 1].title));
            ui->customSetTitle2->setAttribute(Qt::WA_TransparentForMouseEvents);
            ui->customSet2->setIcon(buttonIcon);
            ui->customSet2->setIconSize(QSize(300, 157));
            ui->customSet2->installEventFilter(this);
            customSetsExist = true;
            }
    }
    if(numOfSets >= cardNum + 2){
        if(!customSetsNS::customSets.titles[cardNum + 2].title.empty() && !(customSetsNS::customSets.titles[cardNum + 2].title == " ")){    // Check if there's any information on the card in the vector
            ui->customSetTitle3->setText(QString::fromStdString(customSetsNS::customSets.titles[cardNum + 2].title));
            ui->customSetTitle3->setAttribute(Qt::WA_TransparentForMouseEvents);
            ui->customSet3->setIcon(buttonIcon);
            ui->customSet3->setIconSize(QSize(300, 157));
            ui->customSet3->installEventFilter(this);
            customSetsExist = true;
        }
    }
    if(numOfSets >= cardNum + 3){
        if(!customSetsNS::customSets.titles[cardNum + 3].title.empty() && !(customSetsNS::customSets.titles[cardNum + 3].title == " ")){    // Check if there's any information on the card in the vector
            ui->customSetTitle4->setText(QString::fromStdString(customSetsNS::customSets.titles[cardNum + 3].title));
            ui->customSetTitle4->setAttribute(Qt::WA_TransparentForMouseEvents);
            ui->customSet4->setIcon(buttonIcon);
            ui->customSet4->setIconSize(QSize(300, 157));
            ui->customSet4->installEventFilter(this);
            customSetsExist = true;
        }
    }

    // Show no custom sets text if there are no custom sets
    ui->noSetWarning->setVisible(!customSetsExist);
}


bool dashboard::eventFilter(QObject *obj, QEvent *event) {
    QPushButton *button = qobject_cast<QPushButton*>(obj);
    if (button) {
        if (event->type() == QEvent::Enter) {
            // Enlarge button and icon when hovered
            button->resize(310, 167);
            button->setIconSize(QSize(310, 167));
            button->move(button->pos().x() - 5, button->pos().y() - 5);
            return true;
        } else if (event->type() == QEvent::Leave) {
            // Restore button and icon size when hover ends
            button->resize(300, 157);
            button->setIconSize(QSize(300, 157));
            button->move(button->pos().x() + 5, button->pos().y() + 5);
            return true;
        }
    }
    return QDialog::eventFilter(obj, event); // Call base class for other events
}


dashboard::~dashboard()
{
    delete ui;
}
