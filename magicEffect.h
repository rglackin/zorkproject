#ifndef MAGICEFFECT_H
#define MAGICEFFECT_H
//#include "item.h"

class MagicEffect
{
private:
    int buffAmount;
public:
    MagicEffect(int buffAmount);
    int getBuffAmount() const;
    virtual void applyEffect(class Character& character) const = 0;
};

#endif // MAGICEFFECT_H
