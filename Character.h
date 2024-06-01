#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:
    int health;
    const int maxHealth = 20;
    int baseDefense;
    int baseDamage;
	string description;
     vector < Item> itemsInCharacter;
public:
    void addItem(Item *item);
    void addItem(Item &item);
    void changeHealth(int change);

	Character(string description);
	string shortDescription();
	string longDescription();

    int getBaseDamage() const;
    void changeBaseDamage(int change);
    int getBaseDefense() const;
    void changeBaseDefense(int newBaseDefense);
};

#endif /*CHARACTER_H_*/
