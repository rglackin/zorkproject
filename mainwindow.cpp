#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include "inventorywindow.h"
#include "potion.h"
#include "armour.h"
#include "fightwindow.h"

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
    //

    prevRoom = room;
    room = driverInstance.currentRoom;
    ui->lblRoomName->setText("Room: "+QString::fromStdString(room->getName()));
    ui->lblDesc->setText(QString::fromStdString(room->getDescription()));
    ui->lblRoomName->adjustSize();
    ui->lblDesc->adjustSize();
    ui->lblOutput->setText("");
    ui->lblOutput->adjustSize();
    setPickUpItemsVisibility();
    if(room->enemiesInRoom.size()>0){
        FightWindow* f =new FightWindow(room);
        this->hide();
        f->show();
    }
    updateCharacterLabels();
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
void MainWindow::getStats(){
    QString health= QString::fromStdString(to_string(character.getHealth()));
    QString dmg = QString::fromStdString(to_string(character.getTotalDamage()));
    QString def = QString::fromStdString(to_string(character.getTotalDefense()));
    ui->lblStats->setText("Current Stats:\nHealth: "+health+"/20\nDamage: "+dmg+"\nDefense: "+def);
    ui->lblStats->adjustSize();
}
void MainWindow::getEquip(){
    QString text= QString::fromStdString(character.describeCharacter());

    ui->lblEquip->setText(text);
    ui->lblEquip->adjustSize();
}

void MainWindow::on_btnInv_clicked()
{
    inventoryWindow *nw = new inventoryWindow();
    nw->show();
    this->hide();
}



void MainWindow::on_btnWeapon_clicked()
{
    void(Character::*equipWeaponPtr)(weapon&)=&Character::equipWeapon;
    equipItem<weapon>(equipWeaponPtr, "Weapon:");
}
void MainWindow::updateCharacterLabels(){
    getStats();
    getEquip();
}
template<typename T, typename Func>
void MainWindow::equipItem(Func func,string type){
    vector<Item*> &items = character.getItemsInCharacter();
    vector<T*> desiredItems;
    QStringList itemNames;
    for (Item* item : items) {
        T* t = dynamic_cast<T*>(item);
        if(t!=nullptr){
            desiredItems.push_back(t);
            itemNames << QString::fromStdString(item->getName());
        }
    }
    bool ok;
    QString itemName = QInputDialog::getItem(this, tr("Equip "), tr(type.c_str()), itemNames, 0, false, &ok);
    if (ok && !itemName.isEmpty()) {
        // Find the item with the selected name and remove it from the inventory
        for (T* t :desiredItems) {
            if (t->getName() == itemName.toStdString()) {
                (character.*func)(*t);
            }
        }
    }
    updateCharacterLabels();
}


void MainWindow::on_btnArmour_clicked()
{
    void(Character::*equipArmourPtr)(Armour&)=&Character::equipArmour;
    equipItem<Armour>(equipArmourPtr,"Armour:");
}


void MainWindow::on_btnMagic_clicked()
{
    vector<Item*> &items = character.getItemsInCharacter();
    vector<Potion*> desiredItems;
    QStringList itemNames;
    for (Item* item : items) {
        Potion* t = dynamic_cast<Potion*>(item);
        if(t!=nullptr){
            desiredItems.push_back(t);
            itemNames << QString::fromStdString(item->getName());
        }
    }
    bool ok;
    QString itemName = QInputDialog::getItem(this, tr("Use"), tr("Potion:"), itemNames, 0, false, &ok);
    if (ok && !itemName.isEmpty()) {
        // Find the item with the selected name and remove it from the inventory
        for (Potion* potion : desiredItems) {
            if (potion->getName() == itemName.toStdString()) {
                potion->use(character);
            }
        }
    }
    updateCharacterLabels();
}

