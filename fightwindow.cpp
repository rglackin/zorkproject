#include "fightwindow.h"
#include "ui_fightwindow.h"
#include "fighthandler.h"
#include "mainwindow.h"
#include "endscreen.h"

FightWindow::FightWindow(Room* room,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FightWindow)
    ,fightRoom(room)
    ,player(Character::getCharacterInstance())
{
    ui->setupUi(this);
    if(room->getName()=="Final Boss"){
        bossFight=true;
    }
    Enemy* e = room->getEnemy();
    ui->lblEquip->setText("Player health: "+QString::number(player.getHealth()));
    ui->lblEnemy->setText("Enemy health: "+QString::number(e->getHealth()));
    FightHandler* fight = new FightHandler(e);
    connect(ui->btn_attack, &QPushButton::clicked, fight, &FightHandler::attackTurn);
    connect(fight, &FightHandler::characterHealthChanged, this, &FightWindow::updateCharacterHealth);
    connect(fight, &FightHandler::enemyHealthChanged, this, &FightWindow::updateEnemyHealth);
    connect(fight, &FightHandler::fightOver, this, &FightWindow::handleFightEnd);
}
void FightWindow::updateCharacterHealth(int newHealth){
    ui->lblEquip->setText("Player health: "+QString::number(newHealth));
}
void FightWindow::updateEnemyHealth(int newHealth){
    ui->lblEnemy->setText("Enemy health: "+QString::number(newHealth));
}
void FightWindow::handleFightEnd(bool playerWon){
    if(playerWon){
        if(bossFight){
            //you win
            EndScreen* e = new EndScreen(true);
            e->show();
            this->close();
        }
        else{
            //back to main window
            MainWindow* m = new MainWindow();
            m->show();
            this->close();
        }
    }
    else{
        EndScreen* e = new EndScreen(false);
        e->show();
        this->close();
    }
}
FightWindow::~FightWindow()
{
    delete ui;
}
