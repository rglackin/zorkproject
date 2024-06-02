#include "enemy.h"
#include <string>
using std::string;
Enemy::Enemy(string name, string desc, int damage, int health) {
    this->name = name;
    this->desc = desc;
    this->damage = damage;
    this->health = health;
}
Enemy::Enemy(Enemy &e):Enemy(e.name,e.desc,e.damage,e.health){}
string Enemy::getName(){
    return name;
} ;
string Enemy::getDesc(){
    return desc;
} ;
int Enemy::getDamage() {
    return damage;
};
int Enemy::getHealth(){
    return health;
} ;
void Enemy::setDamage(int newDamage){
    this->damage= newDamage;
};
void Enemy::setHealth(int newHealth){
    this->health=newHealth;
};
