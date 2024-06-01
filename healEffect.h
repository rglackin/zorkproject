#ifndef HEALEFFECT_H
#define HEALEFFECT_H
#include "magicEffect.h"
class HealEffect: public MagicEffect
{
public:
    HealEffect(int buffAmount);
    void applyEffect(Character& c)const override;
};

#endif // HEALEFFECT_H
