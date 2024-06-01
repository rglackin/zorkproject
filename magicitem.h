#ifndef MAGICITEM_H
#define MAGICITEM_H
#include "item.h"
class MagicItem: public Item
{
private:
    int defense;
public:
    MagicItem(int id, const string& name,const string& desc, int weight, float value, int defense);
    //void use() override;
    int getDefense() const;
    void setDefense(int defense);
};

#endif // MAGICITEM_H
