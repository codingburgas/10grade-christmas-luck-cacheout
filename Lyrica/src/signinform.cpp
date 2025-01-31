#include "lib/signinform.h"
#include "ui_signinform.h"

signinForm::signinForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signinForm)
{
    ui->setupUi(this);

    signinForm::displaySignIn();
}

void signinForm::displaySignIn(){
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

void signinForm::actionHandler(PageBools& pages){
    connect(ui->signinButton, &QPushButton::clicked, this, &signinForm::textBoxHandler);
    connect(ui->signinButton, &QPushButton::clicked, this, &signinForm::signInHandler);

    //Page Handling
    connect(ui->signinButton, &QPushButton::clicked, this, [&pages, this](){
        if(signinForm::signInHandler()){
            pages.signInWindowShouldDisplay = false;
            pages.dashboardWindowShouldDisplay = true;
            ui->username->setText("");
            ui->email->setText("");
            ui->password->setText("");
            emit pageStateChanged();
        }
    });

    connect(ui->signupButton, &QPushButton::clicked, this, [&pages, this](){
        pages.signInWindowShouldDisplay = false;
        pages.signUpWindowShouldDisplay = true;
        emit pageStateChanged();
    });
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
    } else ui->warning->setText("Credentials not correct!");
    return false;
}

signinForm::~signinForm()
{
    delete ui;
}
