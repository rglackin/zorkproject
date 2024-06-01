#ifndef MAGICWEAPON_H
#define MAGICWEAPON_H
#include "weapon.h"
#include "potion.h"
class MagicWeapon: public weapon,public Potion
{
public:
    MagicWeapon();
};

#endif // MAGICWEAPON_H
