#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include "inventorywindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,driverInstance(ZorkUL::getInstance())
    ,character(Character::getCharacterInstance())
{
    ui->setupUi(this);
    setupRoom();
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupRoom(){
    room = driverInstance.currentRoom;
    ui->lblRoomName->setText("Room: "+QString::fromStdString(room->getName()));
    ui->lblDesc->setText(QString::fromStdString(room->getDescription()));
    ui->lblRoomName->adjustSize();
    ui->lblDesc->adjustSize();
    ui->lblOutput->setText("");
    ui->lblOutput->adjustSize();
    setPickUpItemsVisibility();

}

void MainWindow::on_btnNorth_clicked()
{
    //call
    goCommand(Direction::NORTH);

}
void MainWindow::on_btnEast_clicked()
{
    goCommand(Direction::EAST);

}
void MainWindow::on_btnSouth_clicked()
{
    goCommand(Direction::SOUTH);
}
void MainWindow::on_btnWest_clicked()
{
    goCommand(Direction::WEST);
}
void MainWindow::goCommand(Direction d){
    string output = driverInstance.go(d);
    if(output == ""){
        setupRoom();
    }
    //dont setup room if no change is made, output only made when exit is invalid
    else{
        ui->lblOutput->setText(QString::fromStdString(output));
        ui->lblOutput->adjustSize();
    }


}
void MainWindow::setPickUpItemsVisibility(){
    if(room->itemsInRoom.empty()){
        ui->btnPickUp->setVisible(false);
    }
    else{
        ui->btnPickUp->setVisible(true);
    }
}

void MainWindow::on_btnPickUp_clicked()
{
    vector<Item*> &items = room->itemsInRoom;
    QStringList itemNames;
    for (Item* item : items) {
        itemNames << QString::fromStdString(item->getName());
    }
    bool ok;
    QString itemName = QInputDialog::getItem(this, tr("Pick Up Item"), tr("Item:"), itemNames, 0, false, &ok);
    if (ok && !itemName.isEmpty()) {
        // Find the item with the selected name and remove it from the room
        for (auto it = items.begin(); it != items.end(); ++it) {
            if ((*it)->getName() == itemName.toStdString()) {
                // Add the item to the character's inventory
                character.addItem(*it);
                // Remove the item from the vector
                items.erase(it);
                break;
            }
        }
    }
    setPickUpItemsVisibility();
}

void MainWindow::on_btnDropItem_clicked()
{
    vector<Item*> &items = character.getItemsInCharacter();
    QStringList itemNames;
    for (Item* item : items) {
        itemNames << QString::fromStdString(item->getName());
    }
    bool ok;
    QString itemName = QInputDialog::getItem(this, tr("Drop Item"), tr("Item:"), itemNames, 0, false, &ok);
    if (ok && !itemName.isEmpty()) {
        // Find the item with the selected name and remove it from the inventory
        for (auto it = items.begin(); it != items.end(); ++it) {
            if ((*it)->getName() == itemName.toStdString()) {
                // Add the item to the character's inventory
                room->addItem(*it);
                // Remove the item from the vector
                items.erase(it);
                break;
            }
        }
    }
    setPickUpItemsVisibility();
}


void MainWindow::on_btnInv_clicked()
{
    inventoryWindow *nw = new inventoryWindow();
    nw->show();
    this->hide();
}

