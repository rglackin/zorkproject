#include "weapon.h"

weapon::weapon( const string& name,const string& desc, int weight, float value,int damage)
    :Item(name,desc, weight, value),damage(damage) {}
weapon::weapon(weapon& i):Item(i){
    damage = i.damage;
}
void weapon::setDamage(int newDamage){
    damage=newDamage;
}
int weapon::getDamage() const{
    return damage;
}

