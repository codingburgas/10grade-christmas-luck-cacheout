#include "lib/signinform.h"
#include "ui_signinform.h"

signinForm::signinForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signinForm)
{
    ui->setupUi(this);
    QPixmap backgroundPix(":/images/assets/signinBackground.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
}

void signinForm::textBoxHandler(){
    QString Username = ui->username->text();
    QString Email = ui->email->text();
    QString Password = ui->password->text();
    credentials::username = Username.toStdString();
    credentials::email = Email.toStdString();
    credentials::password = Password.toStdString();
}

void signinForm::actionHandler(){
    connect(ui->signinButton, &QPushButton::clicked, this, &signinForm::textBoxHandler);
    connect(ui->signinButton, &QPushButton::clicked, this, &signinForm::signInHandler);
}

bool signinForm::signInHandler(){
    std::string fileLine = createSignInFileLine(credentials::username, credentials::email, credentials::password);
    std::fstream credentialsFile("../Lyrica/files/credentials.txt");

    // Ensure the file is open before proceeding
    if (!credentialsFile.is_open()) {
        std::cout << "Error: Could not open the credentials file." << std::endl;
        return false;
    }
    else
        std::cout << "File opened successfully!" << std::endl;

    std::cout << "Trying to match lines in credentials.txt " << fileLine << std::endl;

    // Return the result of checkIfInFile directly
    if(checkIfInFile(credentialsFile, fileLine)){
        std::cout << "Signed in successfully!" << std::endl;
        return true;
    }
    return false;
}

signinForm::~signinForm()
{
    delete ui;
}
