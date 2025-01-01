#ifndef APP_H
#define APP_H
#include <iostream>
#include <QObject>
#include "lib/mainwindow.h"
#include "lib/signinform.h"
#include "lib/signupform.h"
#include "../lib/dashboard.h"
#include "../lib/setexplorer.h"
#include "../lib/practicewindow.h"
#include "../lib/finalwindow.h"
#include "../lib/pageHandler.h"

class App : public QObject{
    Q_OBJECT

public:
    App();
    void signalCatch();

public slots:
    void display();

private:
    MainWindow mainWindow;
    signinForm signIn;
    signupForm signUp;
    dashboard dash;
    SetExplorer setExplorer;
    PracticeWindow practice;
    finalwindow finalWindow;
    PageBools pages;
};

#endif // APP_H
