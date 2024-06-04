QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
#CONFIG -= qt
CONFIG += console
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Character.cpp \
    Room.cpp \
    ZorkUL.cpp \
    armour.cpp \
    atkEffect.cpp \
    directionenum.cpp \
    effectfactory.cpp \
    enemy.cpp \
    exit.cpp \
    healEffect.cpp \
    item.cpp \
    itemfactory.cpp \
    magicEffect.cpp \
    magicweapon.cpp \
    main.cpp \
    mainwindow.cpp \
    potion.cpp \
    weapon.cpp

HEADERS += \
    Character.h \
    Room.h \
    ZorkUL.h \
    armour.h \
    atkEffect.h \
    directionenum.h \
    effectfactory.h \
    enemy.h \
    exit.h \
    globals.h \
    healEffect.h \
    item.h \
    itemfactory.h \
    json.hpp \
    magicEffect.h \
    magicweapon.h \
    mainwindow.h \
    potion.h \
    weapon.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resources.qrc


