#include "healEffect.h"
#include "Character.h"
HealEffect::HealEffect(int buffAmount):
    MagicEffect(buffAmount) {}
void HealEffect::applyEffect(Character& c)const{
    int change = getBuffAmount();
    c.changeHealth(change);
}
