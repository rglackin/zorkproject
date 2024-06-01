#ifndef ITEM_H_
#define ITEM_H_

//#include <map>
#include <string>
//#include <iostream>
using namespace std;

class Item {
protected:
    int id;
    string name;
    string desc;
    int weight;
    int value;
    //bool weaponCheck;

public:
    Item (int id, const string& name,const string& desc, int weight, float value);
    //virtual ~Item();
    //virtual void use()=0;
    //Item (string description);
    string getName();
    string getDesc();
	int getWeight();
	void setWeight(int weightGrams);
    int getValue();
    void setValue(int value);
    //int getWeaponCheck();
    //void setWeaponCheck(int weaponCheck);
};

#endif /*ITEM_H_*/
