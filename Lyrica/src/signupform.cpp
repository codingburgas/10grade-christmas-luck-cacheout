#include "lib/signupform.h"
#include "ui_signupform.h"

signupForm::signupForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signupForm)
{
    ui->setupUi(this);
    signupForm::displaySignUp();
}

void signupForm::displaySignUp(){
    QPixmap backgroundPix(":/images/assets/registerBackground.png");
    ui->background->setPixmap(backgroundPix.scaled(1500, 800, Qt::KeepAspectRatio));
}

void signupForm::textBoxHandler(){
    QString Username = ui->username->text();
    QString Email = ui->email->text();
    QString Password = ui->password->text();
    credentials::username = Username.toStdString();
    credentials::email = Email.toStdString();
    credentials::password = Password.toStdString();
}

void signupForm::actionHandler(PageBools& pages){
    connect(ui->signUpButton, &QPushButton::clicked, this, &signupForm::textBoxHandler);
    connect(ui->signUpButton, &QPushButton::clicked, this, &signupForm::signUpHandler);

    //Page Handling
    connect(ui->signUpButton, &QPushButton::clicked, this, [&pages, this](){
        if(signupForm::signUpHandler()){
            pages.signUpWindowShouldDisplay = false;
            pages.dashboardWindowShouldDisplay = true;
            ui->username->setText("");
            ui->email->setText("");
            ui->password->setText("");
            emit pageStateChanged();
        }
    });

    connect(ui->signinButton, &QPushButton::clicked, this, [&pages, this](){
        pages.signUpWindowShouldDisplay = false;
        pages.signInWindowShouldDisplay = true;
        emit pageStateChanged();
    });
}

bool signupForm::signUpHandler(){
    bool check = false;
    bool checkValid = false;
    std::fstream credentialsFile;
    credentialsFile.open("../Lyrica/files/credentials.txt", std::ios::in | std::ios::out);
    if (!credentialsFile)
        std::cout << "credentials.txt failed to load!" << std::endl;
    else{
        std::cout << "credentials.txt loaded successfully!" << std::endl;
        std::string fileLine = createFileLine(credentials::username, credentials::email, credentials::password);
        std::cout<<fileLine<<std::endl;
        check = checkIfInFileLine(credentialsFile, credentials::username, credentials::email);
        checkValid = checkValidity(credentials::username, credentials::email, credentials::password);
        credentialsFile.close();
        credentialsFile.open("../Lyrica/files/credentials.txt", std::ios::in | std::ios::out | std::ios::app);
        if (!check && checkValid) {
            writeInFile(credentialsFile, fileLine);
            std::cout << "Successfully wrote in file!" << std::endl;
            return !check;
        }
        credentialsFile.close();
    }
    return check;
}

signupForm::~signupForm()
{
    delete ui;
}
