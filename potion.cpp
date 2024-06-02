#include "potion.h"

Potion::Potion( const string& name,const string& desc, int weight, float value,MagicEffect* effect, int uses):
    Item(name,desc,weight,value),effect(effect),uses(uses){}
Potion::Potion(const Potion &i):Item(i){
    effect = i.effect;
    uses = i.uses;
}
int Potion::getUses() const
{
    return uses;
}

/*void Potion::setUses(int newUses)
{
    uses = newUses;
}*/
void Potion::decrementUses(){
    uses--;
}
void Potion::use(class Character& c){
    effect->applyEffect(c);
}
