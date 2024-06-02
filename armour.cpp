#include "armour.h"

Armour::Armour( const string& name,const string& desc, int weight, float value,int defense)
    :Item(name,desc, weight, value),defense(defense) {}
Armour::Armour(Armour &i):Item(i){
    defense = i.defense;
}
void Armour::setDefense(int newDefense){
    defense=newDefense;
}
int Armour::getDefense() const{
    return defense;
}
//TODO implement this
//void Armour::use(){}
