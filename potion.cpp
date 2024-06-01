#include "potion.h"

Potion::Potion(int id, const string& name,const string& desc, int weight, float value,shared_ptr<MagicEffect> effect, int uses):
    Item(id,name,desc,weight,value),effect(effect),uses(uses){}

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
