#include "mainwindow.h"
#include "ZorkUL.h"
#include "Character.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    ZorkUL::getInstance();
    Character::getCharacterInstance();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
