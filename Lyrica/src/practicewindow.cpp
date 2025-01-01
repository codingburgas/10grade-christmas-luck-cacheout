#include "lib/practicewindow.h"
#include "ui_practicewindow.h"

PracticeWindow::PracticeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PracticeWindow)
{
    ui->setupUi(this);

    PracticeWindow::DisplayPracticeWindow();
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

    //Set the flashCard button icon
    QPixmap flashCardPix(":/images/assets/flashCard.png");
    QIcon buttonIcon(flashCardPix);
    ui->flashCard->setIcon(buttonIcon);
    ui->flashCard->setIconSize(QSize(418, 224));
    ui->flashCard->installEventFilter(this); //Apply the hover effect

    // Set the title text
    QString title = "Present Continuous";
    ui->titleTextBox->setText(title);

    // Set the flashcard text
    QString flashCardText = "The present continuous of hover is hovering.";
    ui->flashCardTextBox->setText(flashCardText);
    ui->flashCardTextBox->raise();
    ui->flashCardTextBox->setAttribute(Qt::WA_TransparentForMouseEvents); //Makes the text to not disturb the flashCard hover effect
}

void PracticeWindow::actionHandler(PageBools& pages){
    //Page Handling
    if(finalCard){
        connect(ui->knowTextBox, &QPushButton::clicked, this, [&pages, this](){
            pages.practiceWindowShouldDisplay = false;
            pages.finalWindowShouldDisplay = true;
            emit pageStateChanged();
        });
    }
}

bool PracticeWindow::eventFilter(QObject *obj, QEvent *event){
    QPushButton *button = qobject_cast<QPushButton*>(obj);
    if (button) {
        if (event->type() == QEvent::Enter) {
            // When mouse enters, enlarge button and icon size
            button->resize(428, 234); // Resize button
            button->setIconSize(QSize(428, 234)); // Enlarge icon size
            button->move(button->pos().x() - 5, button->pos().y() - 5);
            return true;
        } else if (event->type() == QEvent::Leave) {
            // When mouse leaves, restore original button and icon size
            button->resize(418, 224); // Restore button size
            button->setIconSize(QSize(418, 224)); // Restore icon size
            button->move(button->pos().x() + 5, button->pos().y() + 5);
            return true;
        }
    }
    return QDialog::eventFilter(obj, event);
}

PracticeWindow::~PracticeWindow()
{
    delete ui;
}
