#ifndef MAGICWEAPON_H
#define MAGICWEAPON_H
#include "weapon.h"
#include "potion.h"
class MagicWeapon: public weapon,public Potion
{

public:
    MagicWeapon(const string& name,const string& desc, int weight, float value, int damage,int uses, MagicEffect* effect);
    MagicWeapon(const MagicWeapon &i);
    virtual MagicWeapon* clone() const {
        return new MagicWeapon(*this);
    }
    void polishWeapon(){
        uses++;
    }
};

#endif // MAGICWEAPON_H
