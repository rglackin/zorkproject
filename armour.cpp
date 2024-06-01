#include "armour.h"

Armour::Armour(int id, const string& name,const string& desc, int weight, float value,int defense):Item( id, name,desc, weight, value),defense(defense) {}

void Armour::setDefense(int newDefense){
    defense=newDefense;
}
int Armour::getDefense() const{
    return defense;
}
//TODO implement this
//void Armour::use(){}
