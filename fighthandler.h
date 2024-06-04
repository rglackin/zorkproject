#ifndef FIGHTHANDLER_H
#define FIGHTHANDLER_H
#include "enemy.h"
#include "Character.h"
#include <QObject>
class FightHandler : public QObject
{
    Q_OBJECT
private:
    Enemy* fightEnemy;
    Character player;
public:
    FightHandler(Enemy *fightEnemies);


    bool startFight();//returns true for win, false for loss
    void playerAttack();
    void enemyAttack();
    void attackTurn();
signals:
    void characterHealthChanged(int newHealth);
    void enemyHealthChanged(int newHealth);
    void fightOver(bool playerwon);
};

#endif // FIGHTHANDLER_H
