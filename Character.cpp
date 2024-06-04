#include "Character.h"

int Character::getHealth() const
{
    return health;
}

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
    if(equippedWeapon==nullptr){

        return baseDamage;
    }
    return baseDamage + equippedWeapon->getDamage();
}

void Character::changeBaseDamage(int change)
{
    baseDamage += change;
}

int Character::getTotalDefense() const
{
    if(equippedArmour==nullptr){

        return baseDefense;
    }
    return baseDefense+ equippedArmour->getDefense();
}

void Character::changeBaseDefense(int change)
{
    baseDefense += change;
}
void Character::changeHealth(int change)
{
    if(change+health>=maxHealth){
        health = maxHealth;
    }
    else{
        health += change;
    }
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
string Character::describeCharacter(){
    string armourEquipped = "No armour equipped." ;
    string weaponEquipped = "No weapon equipped." ;
    if(equippedArmour!=nullptr){
        armourEquipped = "Armour: "+equippedArmour->getName();
    }
    if(equippedWeapon!=nullptr){
        weaponEquipped= "Weapon: "+equippedWeapon->getName();
    }
    return "Current Equipment:\n"+armourEquipped+"\n"+weaponEquipped;

}



