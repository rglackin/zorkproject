#include "Character.h"

Character::Character(string description) {
	this->description = description;
}
void Character::addItem(Item &item) {
    itemsInCharacter.push_back(item);
}
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

void Character::addItem(Item *item) {
    itemsInCharacter.push_back(*item);
    delete item;
}
string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getDesc() + "\n";
  return ret;
}



