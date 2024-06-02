#include "weapon.h"

weapon::weapon( const string& name,const string& desc, int weight, float value,int damage)
    :Item(name,desc, weight, value),damage(damage) {}
weapon::weapon(const weapon &i):Item(i){
    damage = i.damage;
}
string weapon::toString(){
    return Item::toString() +" Damage: "+ to_string(damage);
}
void weapon::setDamage(int newDamage){
    damage=newDamage;
}
int weapon::getDamage() const{
    return damage;
}

