#include "inventorywindow.h"
#include "ui_inventorywindow.h"
#include "mainwindow.h"
#include "Character.h"
#include "magicweapon.h"
#include <QTableWidget>
#include <QVBoxLayout>
#include <QDebug>

inventoryWindow::inventoryWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::inventoryWindow)
{
    ui->setupUi(this);
    populateInv();
    setItemViewVisibility(false);
}

void inventoryWindow::populateInv(){
    Character& c = Character::getCharacterInstance();
    cout<<"No. items in inv:"<<c.getItemsInCharacter().size()<<endl;

    for (Item* item : c.getItemsInCharacter()) {
        int row = ui->tbl_items->rowCount();
        ui->tbl_items->insertRow(row);
        ui->tbl_items->setItem(row, 0,new QTableWidgetItem(QString::fromStdString(item->getName())));
        ui->tbl_items->setItem(row, 1,new QTableWidgetItem(QString::fromStdString(item->getDesc())));
        ui->tbl_items->setItem(row, 2,new QTableWidgetItem(QString::number(item->getValue())));
        ui->tbl_items->setItem(row, 3,new QTableWidgetItem(QString::number(item->getWeight())));

    }
    ui->tbl_items->resizeRowsToContents();

    //QVBoxLayout* layout = new QVBoxLayout(this);
    //layout->addWidget(listWidget);
    //setLayout(layout);
}

inventoryWindow::~inventoryWindow()
{
    delete ui;
}

void inventoryWindow::on_btnExit_clicked()
{
    MainWindow *nw = new MainWindow();
    nw->show();
    this->hide();
}


void inventoryWindow::on_tbl_items_itemSelectionChanged()
{
    Character& c = Character::getCharacterInstance();
    vector<Item*>& items = c.getItemsInCharacter();
    cout<<items.size()<<endl;
    int selectedRow = ui->tbl_items->currentRow();
    if(selectedRow==-1){
        return;
    }
    Item *selectedItem = items[selectedRow];
    if(selectedItem==nullptr){
        return;
    }
    cout<<selectedItem->toString();
    displayItem(selectedItem);
}

void inventoryWindow::displayItem(Item* i){

    ui->lblName->setText("Item: "+ QString::fromStdString(i->getName()));
    ui->lblDesc->setText(""+ QString::fromStdString(i->getDesc()));
    ui->lblValue->setText("Value: "+ QString::number(i->getValue()));
    ui->lblWeight->setText("Weight: "+ QString::number(i->getWeight()));
    string dmg ="";
    string def = "";
    string eff = "";
    string use ="";

    MagicWeapon* mw = dynamic_cast<MagicWeapon*>(i);
    weapon* w = dynamic_cast<weapon*>(i);
    Armour* a = dynamic_cast<Armour*>(i);
    Potion* p = dynamic_cast<Potion*>(i);
    if (mw != nullptr) {
        dmg = "Damage: " + to_string(mw->getDamage());
        eff = "Effect: " + mw->effectString();
        use = "Uses: " + to_string(mw->getUses());
    }
    else if (w != nullptr) {
        dmg = "Damage: " + to_string(w->getDamage());
    }
    else if (a != nullptr) {
        def = "Defense: " + to_string(a->getDefense());
    }
    else if (p != nullptr) {
        eff = "Effect: " + p->effectString();
        use = "Uses: " + to_string(p->getUses());
    }
    ui->lblDamage->setText(QString::fromStdString(dmg));
    ui->lblDefense->setText(QString::fromStdString(def));
    ui->lblEffect->setText(QString::fromStdString(eff));
    ui->lblUses->setText(QString::fromStdString(use));
    setItemViewVisibility(true);
}
void inventoryWindow::setItemViewVisibility(bool b){
    QLabel* lblArr[8] = {ui->lblName,ui->lblDesc,ui->lblDamage,ui->lblDefense,ui->lblValue,ui->lblWeight,ui->lblEffect,ui->lblUses};
    QLabel** ptr = lblArr;
    for (int var = 0; var < 8; ++var) {
        (*(ptr+var))->setVisible(b);
        (*(ptr+var))->adjustSize();
    }
    ui->btnShowTable->setVisible(b);
    ui->tbl_items->setVisible(!b);
}


void inventoryWindow::on_btnShowTable_clicked()
{
    setItemViewVisibility(false);
}

