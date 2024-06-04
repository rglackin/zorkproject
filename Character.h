#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"
#include "weapon.h"
#include "armour.h"
#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:
    int health;
    const int maxHealth = 20;
    int baseDefense ;
    int baseDamage ;
    vector <Item*> itemsInCharacter;
    weapon* equippedWeapon;
    Armour* equippedArmour;
    Character();
public:
    void addItem(Item *item);
    void removeItem(Item *item);
    void changeHealth(int change);
    void equipWeapon(weapon& w);
    void equipArmour(Armour& a);
    static Character& getCharacterInstance();
    vector<Item*>& getItemsInCharacter();
    int getTotalDamage() const;
    void changeBaseDamage(int change);
    int getTotalDefense() const;
    void changeBaseDefense(int newBaseDefense);
};

#endif /*CHARACTER_H_*/
