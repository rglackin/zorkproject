#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"
class weapon: virtual public Item
{
private:
    int damage;
public:
    weapon(const weapon& i);
    weapon(/*int id,*/ const string& name,const string& desc, int weight, float value, int damage);
    virtual weapon* clone() const override {
        return new weapon(*this);
    }
    string toString() override;
    //void use() override;
    int getDamage() const;
    void setDamage(int damage);
};

#endif // WEAPON_H
