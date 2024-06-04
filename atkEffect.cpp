#include "atkEffect.h"
#include "Character.h"
AtkEffect::AtkEffect(int buffAmount):
    MagicEffect(buffAmount){}
void AtkEffect::applyEffect(Character& c)const{
    int change = getBuffAmount();
    c.changeBaseDamage(change);
}
string AtkEffect::effectString(){
    return "Buffs your damage by "+to_string(getBuffAmount());
}
