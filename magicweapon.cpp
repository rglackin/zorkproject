#include "magicweapon.h"

MagicWeapon::MagicWeapon( const string& name,const string& desc, int weight, float value, int damage,int uses, MagicEffect* effect):
    Item(name,desc,weight,value),
    weapon(name,desc,weight,value,damage),
    Potion(name,desc,weight,value,effect,uses){}
MagicWeapon::MagicWeapon(MagicWeapon &i)
    :Item(i),weapon(i),Potion(i){}
