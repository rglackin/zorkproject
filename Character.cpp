#include "Character.h"

Character::Character() {
    this->health = this->maxHealth;
    this->baseDamage = 0;
    this->baseDefense = 0;
}
Character& Character::getCharacterInstance(){
    static Character instance;
    return instance;
}
/*void Character::addItem(Item &item) {
    itemsInCharacter.push_back(item);
}*/
int Character::getTotalDamage() const
{
    return baseDamage + equippedWeapon->getDamage();
}

void Character::changeBaseDamage(int change)
{
    baseDamage += change;
}

int Character::getTotalDefense() const
{
    return baseDefense+ equippedArmour->getDefense();
}

void Character::changeBaseDefense(int change)
{
    baseDefense += change;
}
void Character::changeHealth(int change)
{
    health += change;
}
void Character::addItem(Item *item) {
    Item *copyItem = item->clone();
    delete item;
    itemsInCharacter.push_back(copyItem);
}
vector<Item*>& Character::getItemsInCharacter(){
    return itemsInCharacter;
}
void Character::equipWeapon(weapon& w){
    equippedWeapon = &w;
}
void Character::equipArmour(Armour& a){
    equippedArmour= &a;
}


