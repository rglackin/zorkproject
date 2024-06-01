#ifndef ARMOUR_H
#define ARMOUR_H
#include "item.h"
class Armour: public Item
{
private:
    int defense;
public:
    Armour(int id, const string& name,const string& desc, int weight, float value, int defense);
    //void use() override;
    int getDefense() const;
    void setDefense(int defense);

};

#endif // ARMOUR_H
