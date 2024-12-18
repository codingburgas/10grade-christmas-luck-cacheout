#include "lib/practicewindow.h"
#include "ui_practicewindow.h"

HoverLabel::HoverLabel(QWidget *parent) : QLabel(parent) {
    setScaledContents(true); // Ensures pixmap scales with label size
}

void HoverLabel::enterEvent(QEnterEvent *event) {
    QPoint currentPos = this->pos();
    int currentWidth = this->width();
    int currentHeight = this->height();

    int moveX = currentWidth * 0.025;
    int moveY = currentHeight * 0.025;

    this->move(currentPos.x() - moveX, currentPos.y() - moveY);
    this->resize(this->width() * 1.05, this->height() * 1.05);
    QLabel::enterEvent(event);
}

void HoverLabel::leaveEvent(QEvent *event) {
    QPoint currentPos = this->pos();
    int currentWidth = this->width();
    int currentHeight = this->height();

    this->move(currentPos.x() + currentWidth * 0.025, currentPos.y() + currentHeight * 0.025);

    this->resize(this->width() / 1.05, this->height() / 1.05);
    QLabel::leaveEvent(event);
}

PracticeWindow::PracticeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PracticeWindow)
{
    ui->setupUi(this);

    DisplayPracticeWindow();
}

void PracticeWindow::DisplayPracticeWindow(){
    // Load the custom font
    int fontId = QFontDatabase::addApplicationFont(":/fonts/assets/SpaceGrotesk.ttf");
    if (fontId == -1)
        qDebug() << "Failed to load custom font.";
    else
        qDebug() << "Custom font loaded successfully.";
    QString fontSpaceGrotesk = QFontDatabase::applicationFontFamilies(fontId).at(0);

    // Load the images
    QPixmap backgroundPix(":/images/assets/mainBackground.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));

    //Add hover effect to the flashcard
    flashCardHover = new HoverLabel(this);
    flashCardHover->setGeometry(ui->flashCard->geometry());
    flashCardHover->setParent(this);

    QPixmap flashCardPix(":/images/assets/flashCard.png");
    flashCardHover->setPixmap(flashCardPix.scaled(418, 224, Qt::KeepAspectRatio));

    // Set the title text
    QString title = "Present Continuous";
    ui->titleTextBox->setText(title);

    // Set the flashcard text
    QString flashCardText = "The present continuous of hover is hovering.";
    ui->flashCardTextBox->setText(flashCardText);
    ui->flashCardTextBox->raise();
    ui->flashCardTextBox->setAttribute(Qt::WA_TransparentForMouseEvents);
}

PracticeWindow::~PracticeWindow()
{
    delete ui;
}
