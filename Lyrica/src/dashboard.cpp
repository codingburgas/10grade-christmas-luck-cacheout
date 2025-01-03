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
    QPixmap card(":/images/assets/card.png");
    QPixmap backgroundPix(":/images/assets/dashboardBg.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));

    QString dashUsername = QString::fromStdString(credentials::username);
    ui->username->setText(dashUsername + "!");

    QList<QPushButton*> CardList = { ui->set1, ui->set2 ,ui->set3, ui->set4, ui->customSet1, ui->customSet2 ,ui->customSet3, ui->customSet4 };

    for (QPushButton* button : CardList) {
        if (button) {
            QIcon buttonIcon(card);
            button->setIcon(buttonIcon);
            button->setIconSize(QSize(300, 157));
            button->installEventFilter(this);
        }
    }
}

void dashboard::actionHandler(PageBools& pages){
    dashboard::displayDashboard();

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
