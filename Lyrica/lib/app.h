#ifndef APP_H
#define APP_H
#include <iostream>
#include "lib/mainwindow.h"
#include "lib/signinform.h"
#include "lib/signupform.h"

class App{
public:
    App();
    void display();


private:
    MainWindow mainWindow;
    signinForm signIn;
    signupForm signUp;
};

#endif // APP_H
