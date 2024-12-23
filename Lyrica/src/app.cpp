#include "lib/app.h"

App::App(){
    App::display();
}

void App::display(){
    signIn.show();
    signIn.actionHandler();
}
