#include "itemfactory.h"
#include "armour.h"
#include "magicweapon.h"
#include "globals.h"

ItemFactory::ItemFactory() {}
ItemType stringToType(const string& str) {
    static const std::map<string, ItemType> typeMap = {
        {"misc", ItemType::ITEM},
        {"armour", ItemType::ARMOUR},
        {"weapon", ItemType::WEAPON},
        {"potion", ItemType::POTION},
        {"magic_weapon", ItemType::MAGICWEAPON}
    };
    auto it = typeMap.find(str);
    if (it != typeMap.end()) {
        return it->second;
    } else {
        throw invalid_argument("Invalid item type input");
    }
}
Item* ItemFactory::createItem(QJsonObject obj){
    Item* item = nullptr;
    string typeString = obj["type"].toString().toStdString();
    ItemType type = stringToType(typeString);
    string name = obj["name"].toString().toStdString();
    string desc = obj["description"].toString().toStdString();
    int value = obj["value"].toInt();
    int weight = obj["weight"].toInt();
    int defense=0;
    int dmg=0;
    int effectId=0;
    int uses=0;
    MagicEffect* effect = nullptr;



    switch (type) {
    case ITEM:
        item = new Item(name,desc,weight,value);
        break;
    case ARMOUR:
        defense = obj["defense"].toInt();
        item = new Armour(name,desc,weight,value,defense);
        break;
    case WEAPON:
        dmg= obj["damage"].toInt();
        item = new weapon(name,desc,weight,value,dmg);
        break;
    case POTION:
        effectId = obj["effect"].toInt();
        effect = effectMap[effectId];
        uses = obj["uses"].toInt();
        item = new Potion(name,desc,weight,value,effect,uses);
        //item = item
        break;
    case MAGICWEAPON:
        effectId = obj["effect"].toInt();
        effect = effectMap[effectId];
        uses = obj["uses"].toInt();
        dmg= obj["damage"].toInt();
        item = new MagicWeapon(name,desc,weight,value,dmg,uses,effect);
        //item = new MagicWeapon(name,desc,value,weight)
        break;
    }
    return item;
}
