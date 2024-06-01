#ifndef ATKEFFECT_H
#define ATKEFFECT_H
#include "magicEffect.h"
class AtkEffect:public MagicEffect
{
public:
    AtkEffect(int buffAmount);
    void applyEffect(class Character& c) const override;
};

#endif // ATKEFFECT_H
