#ifndef ARMOUR_H
#define ARMOUR_H
#include "item.h"
class Armour: public Item
{
private:
    int defense;
public:
    Armour(const string& name,const string& desc, int weight, float value, int defense);
    Armour(const Armour &i);
    virtual Armour* clone() const {
        return new Armour(*this);
    }

    int getDefense() const;
    void setDefense(int defense);

};

#endif // ARMOUR_H
