#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include <QJsonObject>
#include "item.h"
enum ItemType{
    ITEM ,
    ARMOUR ,
    WEAPON ,
    POTION ,
    MAGICWEAPON
};
class ItemFactory
{

public:
    ItemFactory();
    static Item* createItem(QJsonObject obj);
};

#endif // ITEMFACTORY_H
