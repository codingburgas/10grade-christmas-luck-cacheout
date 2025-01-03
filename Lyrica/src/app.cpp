#include "lib/app.h"

App::App(){
    App::signalCatch();
    App::display();
}

void App::signalCatch(){
    QObject::connect(&mainWindow, &MainWindow::pageStateChanged, this, &App::display);
    QObject::connect(&signUp, &signupForm::pageStateChanged, this, &App::display);
    QObject::connect(&signIn, &signinForm::pageStateChanged, this, &App::display);
    QObject::connect(&dash, &dashboard::pageStateChanged, this, &App::display);
    QObject::connect(&setExplorer, &SetExplorer::pageStateChanged, this, &App::display);
    QObject::connect(&cardCreate, &cardCreation::pageStateChanged, this, &App::display);
    QObject::connect(&practice, &PracticeWindow::pageStateChanged, this, &App::display);
    QObject::connect(&finalWindow, &finalwindow::pageStateChanged, this, &App::display);
}

void App::display(){
    if(pages.mainWindowShouldDisplay){
        mainWindow.actionHandler(pages);
        mainWindow.show();
    } else mainWindow.hide();

    if(pages.signUpWindowShouldDisplay){
        signUp.actionHandler(pages);
        signUp.show();
    } else signUp.hide();

    if(pages.signInWindowShouldDisplay){
        signIn.show();
        signIn.actionHandler(pages);
    } else signIn.hide();

    if(pages.dashboardWindowShouldDisplay){
        dash.show();
        dash.actionHandler(pages);
    } else dash.hide();

    if(pages.setExplorerWindowShouldDisplay){
        setExplorer.show();
        setExplorer.actionHandler(pages);
    } else setExplorer.hide();

    if(pages.cardCreationShouldDisplay){
        cardCreate.show();
        cardCreate.actionHandler(pages);
    } else cardCreate.hide();

    if(pages.practiceWindowShouldDisplay){
        practice.show();
        practice.actionHandler(pages);
    } else practice.hide();

    if(pages.finalWindowShouldDisplay){
        finalWindow.show();
        finalWindow.actionHandler(pages);
    }else finalWindow.hide();
}
