QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SOURCES += \
    BLL/src/credentials.cpp \
    BLL/src/signin.cpp \
    BLL/src/signup.cpp \
    DAL/src/files.cpp \
    models/card.cpp \
    models/customset.cpp \
    models/user.cpp \
    src/app.cpp \
    src/pageHandler.cpp \
    src/signinform.cpp \
    src/signupform.cpp \
    src/dashboard.cpp \
    src/practicewindow.cpp \
    src/finalwindow.cpp \
    src/cardcreation.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/setexplorer.cpp


HEADERS += \
    BLL/lib/credentials.h \
    BLL/lib/precompileBLL.h \
    BLL/lib/signup.h \
    BLL/lib/signin.h \
    DAL/lib/files.h \
    lib/app.h \
    lib/mainwindow.h \
    lib/pageHandler.h \
    lib/signinform.h \
    lib/setexplorer.h \
    lib/dashboard.h \
    lib/practicewindow.h \
    lib/finalwindow.h \
    lib/signupform.h \
    lib/cardcreation.h \
    models/card.h \
    models/customset.h \
    models/user.h

FORMS += \
    ui/dashboard.ui \
    ui/signupform.ui \
    ui/signinform.ui \
    ui/practicewindow.ui \
    ui/setexplorer.ui \
    ui/finalwindow.ui \
    ui/cardcreation.ui \
    ui/mainwindow.ui

FORMS += \
    
     
RESOURCES += \
    signupBg.qrc \
    signinBg.qrc \
    cardCreateBg.qrc \
    mainwindow.qrc
