#include "weapon.h"

weapon::weapon(int id, const string& name,const string& desc, int weight, float value,int damage):Item( id, name,desc, weight, value),damage(damage) {}

void weapon::setDamage(int newDamage){
    damage=newDamage;
}
int weapon::getDamage() const{
    return damage;
}

