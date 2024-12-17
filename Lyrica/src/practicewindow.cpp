#include "lib/practicewindow.h"
#include "ui_practicewindow.h"

PracticeWindow::PracticeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PracticeWindow)
{
    ui->setupUi(this);

    int fontId = QFontDatabase::addApplicationFont(":/fonts/assets/SpaceGrotesk.ttf");
    if (fontId == -1) qDebug() << "Failed to load custom font.";
    else qDebug() << "Custom font loaded successfully:";
    QString fontSpaceGrotesk = QFontDatabase::applicationFontFamilies(fontId).at(0);


    //Loading the images
    QPixmap backgroundPix(":/images/assets/mainBackground.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
    QPixmap flashCardPix(":/images/assets/flashCard.png");
    ui->flashCard->setPixmap(flashCardPix.scaled(418, 224, Qt::KeepAspectRatio));

    QString title = "Top 10 favorite huyove";
    ui->titleTextBox->setText(title);

    QString flashCardText = "wgaushgeuiaui AGIUA Hakugha eiu23";
    ui->flashCardTextBox->setText(flashCardText);
}



PracticeWindow::~PracticeWindow()
{
    delete ui;
}
