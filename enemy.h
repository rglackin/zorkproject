#ifndef ENEMY_H
#define ENEMY_H

#include <string>
using std::string;

class Enemy
{
private:
    int id;
    string name;
    string desc;
    int damage;
    int health;

public:
    Enemy(int id,  string name,  string desc, int damage, int health);
    int getId() ;
    string getName() ;
    string getDesc() ;
    int getDamage() ;
    int getHealth() ;
    void setDamage(int newDamage);
    void setHealth(int newHealth);
};

#endif // ENEMY_H
