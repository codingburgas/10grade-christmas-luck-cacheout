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
    DAL/src/files.cpp \
    src/app.cpp \
    src/signinform.cpp \
    BLL/src/signup.cpp \
    src/signupform.cpp \
    src/dashboard.cpp \
    src/setexplorer.cpp \
    src/practicewindow.cpp \
    src/main.cpp \
    src/mainwindow.cpp


HEADERS += \
    BLL/lib/credentials.h \
    BLL/lib/precompileBLL.h \
    BLL/lib/signup.h \
    BLL/lib/signin.h \
    DAL/lib/files.h \
    lib/app.h \
    lib/mainwindow.h \
    lib/signinform.h \
    lib/setexplorer.h \
    lib/dashboard.h \
    lib/practicewindow.h \
    lib/signupform.h

FORMS += \
    ui/dashboard.ui \
    ui/signupform.ui \
    ui/signinform.ui \
    ui/practicewindow.ui \
    ui/setexplorer.ui \
    ui/mainwindow.ui
    
RESOURCES += \
    signupBg.qrc \
    signinBg.qrc \
    mainwindow.qrc
