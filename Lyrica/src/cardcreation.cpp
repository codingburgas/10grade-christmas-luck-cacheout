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
    numOfCards = 0;
}

void cardCreation::on_submit_clicked()
{
    // QString savingGoalAmount = ui->targetInput->text();
    // QString savingGoalName = ui->nameInpu->text();
    // savingGoal goal;
    // goal.name = savingGoalName.toStdString();
    // goal.req = savingGoalAmount.toDouble();
    // currentUser.savingGoals.push_back(goal);
     numOfCards++;
     qDebug() << "Number of cards:" << numOfCards;
     currentSet.numCards=  numOfCards;

    currentSet.cards.push_back(card());

    QString title = ui->titleinput->text();
    QString frontSideCurrent = ui->frontInput->text();
    QString backSideCurrent = ui->backinput->text();
    currentSet.title = title.toStdString();
    currentSet.cards[numOfCards - 1].frontSide = frontSideCurrent.toStdString();
    currentSet.cards[numOfCards - 1].backSide = backSideCurrent.toStdString();
    ui->frontInput->setText("");
    ui->frontInput->setText("");
    ui->backinput->setText("");
}

cardCreation::~cardCreation()
{
    delete ui;
}




