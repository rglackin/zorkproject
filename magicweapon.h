#ifndef MAGICWEAPON_H
#define MAGICWEAPON_H
#include "weapon.h"
#include "potion.h"
class MagicWeapon: public weapon,public Potion
{
public:
    MagicWeapon(const string& name,const string& desc, int weight, float value, int damage,int uses, MagicEffect* effect);
    MagicWeapon(MagicWeapon &i);
};

#endif // MAGICWEAPON_H
