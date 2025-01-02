QT       += core gui

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
    models/card.cpp \
    models/customset.cpp \
    models/user.cpp \
    src/cardcreation.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    lib/cardcreation.h \
    models/card.h \
    models/customset.h \
    lib/mainwindow.h \
    models/user.h

FORMS += \
    ui/cardcreation.ui \
    ui/mainwindow.ui

RESOURCES += \
    cardCreateBg.qrc \
    mainwindow.qrc
