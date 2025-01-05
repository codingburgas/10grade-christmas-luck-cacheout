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

    for (QPushButton* button : addCardList) {
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
}

void SetExplorer::displaySets(){
    QString set1Title = QString::fromStdString(readySetsNS::readySets.titles[numOfTitles].title);

    std::cout << readySetsNS::readySets.numTitles << std::endl;
    std::cout << readySetsNS::readySets.titles[numOfTitles].title << std::endl;
    ui->set1->setText(set1Title);
    qDebug() << set1Title;
}

// Event filter to handle hover events
bool SetExplorer::eventFilter(QObject *obj, QEvent *event) {
    QPushButton *button = qobject_cast<QPushButton*>(obj);
    if (button) {
        if (event->type() == QEvent::Enter) {
            // When mouse enters, enlarge button and icon size
            button->resize(310, 167); // Resize button
            button->setIconSize(QSize(310, 167)); // Enlarge icon size
            return true;
        } else if (event->type() == QEvent::Leave) {
            // When mouse leaves, restore original button and icon size
            button->resize(300, 157); // Restore button size
            button->setIconSize(QSize(300, 157)); // Restore icon size
            return true;
        }
    }
    return QDialog::eventFilter(obj, event);
}

SetExplorer::~SetExplorer()
{
    delete ui;
}
