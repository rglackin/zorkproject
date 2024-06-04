#include "mainwindow.h"
#include "ZorkUL.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    ZorkUL::getInstance();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
