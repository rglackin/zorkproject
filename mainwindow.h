#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZorkUL.h"
#include "Character.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnNorth_clicked();

    void on_btnWest_clicked();

    void on_btnEast_clicked();

    void on_btnSouth_clicked();

    void on_btnPickUp_clicked();
    void setupRoom();
    void goCommand(Direction d);
    void setPickUpItemsVisibility();

    void on_btnDropItem_clicked();

    void on_btnInv_clicked();

private:
    Ui::MainWindow *ui;
    ZorkUL& driverInstance;
    Character& character;
    Room* room = nullptr;
};
#endif // MAINWINDOW_H
