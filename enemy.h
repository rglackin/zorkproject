#ifndef ENEMY_H
#define ENEMY_H

#include <string>
using std::string;

class Enemy
{
private:
    string name;
    string desc;
    int damage;
    int health;

public:
    Enemy( string name,  string desc, int damage, int health);
    Enemy(Enemy &e);
    string getName() ;
    string getDesc() ;
    int getDamage() ;
    int getHealth() ;
    void setDamage(int newDamage);
    void setHealth(int newHealth);
};

#endif // ENEMY_H
