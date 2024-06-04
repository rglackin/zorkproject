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
int Character::getBaseDamage() const
{
    return baseDamage;
}

void Character::changeBaseDamage(int change)
{
    baseDamage += change;
}

int Character::getBaseDefense() const
{
    return baseDefense;
}

void Character::changeBaseDefense(int change)
{
    baseDefense += change;
}
void Character::changeHealth(int change)
{
    health += change;
}

/*void Character::addItem(Item *item) {
    itemsInCharacter.push_back(*item);
    delete item;
}*/




