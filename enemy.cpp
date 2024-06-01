#include "enemy.h"
#include <string>
using std::string;
Enemy::Enemy(int id,  string name, string desc, int damage, int health) {
    this->id = id;
    this->name = name;
    this->desc = desc;
    this->damage = damage;
    this->health = health;
}
int Enemy:: getId() {
    return id;
};
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
