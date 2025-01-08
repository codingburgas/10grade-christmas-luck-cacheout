#include "lib/setexplorer.h"
#include "ui_setexplorer.h"
#include <QPushButton>
#include <QEvent>
#include <QDebug>

SetExplorer::SetExplorer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetExplorer)
{
    ui->setupUi(this);
    SetExplorer::displaySetExplorer();
}

void SetExplorer::displaySetExplorer(){
    QPixmap backgroundIm(":/images/assets/mainBackground.png");
    QPixmap card(":/images/assets/flashCard.png");
    ui->background->setPixmap(backgroundIm.scaled(1500, 800, Qt::KeepAspectRatio));

    QList<QPushButton*> addCardList = {
        ui->set1, ui->set2, ui->set3, ui->set4, ui->set5, ui->set6, ui->set7, ui->set8, ui->set9, ui->set10, ui->set11, ui->set12
    };

    for (QPushButton* button : addCardList) {      // Set the same properties on all cards
        if (button) {
            QIcon buttonIcon(card);
            button->setIcon(buttonIcon);
            button->setIconSize(QSize(300, 157));
            button->installEventFilter(this);
        }
    }
}

void SetExplorer::actionHandler(PageBools& pages){
    SetExplorer::displaySets();

    //Page handling
    connect(ui->set1, &QPushButton::clicked, this, [&pages, this](){
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });
    connect(ui->backArrow, &QPushButton::clicked, this, [&pages, this](){
        pages.setExplorerWindowShouldDisplay = false;
        pages.dashboardWindowShouldDisplay = true;
        emit pageStateChanged();
    });


    //Card Handling
    connect(ui->set1, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::numTitles = 1;
        readySetsNS::active = true;
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });
    connect(ui->set2, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::numTitles = 2;
        readySetsNS::active = true;
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set3, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::numTitles = 3;
        readySetsNS::active = true;
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set4, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::numTitles = 4;
        readySetsNS::active = true;
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set5, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::numTitles = 5;
        readySetsNS::active = true;
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set6, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::numTitles = 6;
        readySetsNS::active = true;
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set7, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::numTitles = 7;
        readySetsNS::active = true;
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set8, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::numTitles = 8;
        readySetsNS::active = true;
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set9, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::numTitles = 9;
        readySetsNS::active = true;
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set10, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::numTitles = 10;
        readySetsNS::active = true;
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set11, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::numTitles = 11;
        readySetsNS::active = true;
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });

    connect(ui->set12, &QPushButton::clicked, this, [&pages, this](){
        readySetsNS::numTitles = 12;
        readySetsNS::active = true;
        pages.setExplorerWindowShouldDisplay = false;
        pages.practiceWindowShouldDisplay = true;
        emit pageStateChanged();
    });
}

void SetExplorer::displaySets(){
    QString set1Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles].title);
    QString set2Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles + 1].title);
    QString set3Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles + 2].title);
    QString set4Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles + 3].title);
    QString set5Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles + 4].title);
    QString set6Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles + 5].title);
    QString set7Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles + 6].title);
    QString set8Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles + 7].title);
    QString set9Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles + 8].title);
    QString set10Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles + 9].title);
    QString set11Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles + 10].title);
    QString set12Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles + 11].title);

    // Set the respective set title on each card in order
    ui->set1Text->setText(set1Title);
    ui->set1Text->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->set2Text->setText(set2Title);
    ui->set2Text->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->set3Text->setText(set3Title);
    ui->set3Text->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->set4Text->setText(set4Title);
    ui->set4Text->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->set5Text->setText(set5Title);
    ui->set5Text->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->set6Text->setText(set6Title);
    ui->set6Text->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->set7Text->setText(set7Title);
    ui->set7Text->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->set8Text->setText(set8Title);
    ui->set8Text->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->set9Text->setText(set9Title);
    ui->set9Text->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->set10Text->setText(set10Title);
    ui->set10Text->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->set11Text->setText(set11Title);
    ui->set11Text->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->set12Text->setText(set12Title);
    ui->set12Text->setAttribute(Qt::WA_TransparentForMouseEvents);
}

// Event filter to handle hover events
bool SetExplorer::eventFilter(QObject *obj, QEvent *event) {
    QPushButton *button = qobject_cast<QPushButton*>(obj);
    if (button) {
        if (event->type() == QEvent::Enter) {
            // When mouse enters, enlarge button and icon size
            button->resize(310, 167); // Resize button
            button->setIconSize(QSize(310, 167)); // Enlarge icon size
            button->move(button->pos().x() - 5, button->pos().y() - 5);
            return true;
        } else if (event->type() == QEvent::Leave) {
            // When mouse leaves, restore original button and icon size
            button->resize(300, 157); // Restore button size
            button->setIconSize(QSize(300, 157)); // Restore icon size
            button->move(button->pos().x() + 5, button->pos().y() + 5);
            return true;
        }
    }
    return QDialog::eventFilter(obj, event);
}

SetExplorer::~SetExplorer()
{
    delete ui;
}
