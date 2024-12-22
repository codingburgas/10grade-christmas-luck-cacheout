#ifndef APP_H
#define APP_H

#include <iostream>
#include "lib/signupform.h"

class App{
public:
    App();
    void display();


private:
    signupForm signUp;
};

#endif // APP_H
