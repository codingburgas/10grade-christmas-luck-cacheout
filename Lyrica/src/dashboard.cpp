#include "lib/dashboard.h"
#include "ui_dashboard.h"
#include <QPushButton>
#include <QEvent>

dashboard::dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dashboard)
{
    ui->setupUi(this);

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
        pages.signUpWindowShouldDisplay = true;
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
        } else if (setsGroup2) {
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

    for (QPushButton* button : CardList) {
        if (button) {
            QIcon buttonIcon(card);
            button->setIcon(buttonIcon);
            button->setIconSize(QSize(300, 157));
            button->installEventFilter(this);
        }
    }

    ui->setTitle1->setText(QString::fromStdString(readySetsNS::readySets.titles[cardNum].title));
    ui->setTitle2->setText(QString::fromStdString(readySetsNS::readySets.titles[cardNum + 1].title));
    ui->setTitle3->setText(QString::fromStdString(readySetsNS::readySets.titles[cardNum + 2].title));
    ui->setTitle4->setText(QString::fromStdString(readySetsNS::readySets.titles[cardNum + 3].title));


}
void  dashboard::displayCustomSets(int cardNum){
    QPixmap card(":/images/assets/card.png");
    QIcon buttonIcon(card);


    int numOfSets = customSetsNS::customSets.numTitles;
    if(numOfSets == 0)  ui->noSetWarning->setText("No custom sets yet !");
    if(numOfSets >= cardNum ){
        ui->customSetTitle1->setText(QString::fromStdString(customSetsNS::customSets.titles[cardNum].title));
        ui->customSet1->setIcon(buttonIcon);
        ui->customSet1->setIconSize(QSize(300, 157));
    }
    if(numOfSets >= cardNum + 1){
        ui->customSetTitle2->setText(QString::fromStdString(customSetsNS::customSets.titles[cardNum + 1].title));
        ui->customSet2->setIcon(buttonIcon);
        ui->customSet2->setIconSize(QSize(300, 157));
    }
    if(numOfSets >= cardNum + 2){
        ui->customSetTitle3->setText(QString::fromStdString(customSetsNS::customSets.titles[cardNum + 2].title));
        ui->customSet3->setIcon(buttonIcon);
        ui->customSet3->setIconSize(QSize(300, 157));
    }
    if(numOfSets >= cardNum + 3){
        ui->customSetTitle4->setText(QString::fromStdString(customSetsNS::customSets.titles[cardNum + 3].title));
        ui->customSet4->setIcon(buttonIcon);
        ui->customSet4->setIconSize(QSize(300, 157));
    }
}

bool dashboard::eventFilter(QObject *obj, QEvent *event) {
    QPushButton *button = qobject_cast<QPushButton*>(obj);
    if (button) {
        if (event->type() == QEvent::Enter) {
            // Enlarge button and icon when hovered
            button->resize(310, 167);
            button->setIconSize(QSize(310, 167));
            return true;
        } else if (event->type() == QEvent::Leave) {
            // Restore button and icon size when hover ends
            button->resize(300, 157);
            button->setIconSize(QSize(300, 157));
            return true;
        }
    }
    return QDialog::eventFilter(obj, event); // Call base class for other events
}

dashboard::~dashboard()
{
    delete ui;
}
