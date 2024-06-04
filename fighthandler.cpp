#include "fighthandler.h"

FightHandler::FightHandler(Enemy *fightEnemy) : fightEnemy(fightEnemy),
    player(Character::getCharacterInstance())
{}

void FightHandler::attackTurn(){
    playerAttack();
    enemyAttack();
}
void FightHandler::playerAttack(){
    int damage = player.getTotalDamage();
    if(damage>0){
        fightEnemy->setHealth(fightEnemy->getHealth()-damage);
        if(fightEnemy->getHealth()>0){
            emit enemyHealthChanged(fightEnemy->getHealth());
        }
        else{
            emit fightOver(true);
        }
    }
}
void FightHandler::enemyAttack(){
    int damage = fightEnemy->getDamage()-player.getTotalDefense();
    if(damage>0){
        player.changeHealth(damage);
        if(player.getHealth()>0){
            emit characterHealthChanged(player.getHealth());
        }
        else{
            emit fightOver(false);
        }

    }
}
