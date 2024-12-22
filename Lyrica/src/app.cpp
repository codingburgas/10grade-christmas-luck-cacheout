#include "lib/app.h"

App::App(){
    App::display();
}

void App::display(){
    signUp.show();
    signUp.actionHandler();
}
