#ifndef ITEM_H_
#define ITEM_H_

//#include <map>
#include <string>
//#include <iostream>
using namespace std;

class Item {
private:
    /*int id;*/
    string name;
    string desc;
    int weight;
    int value;
    //bool weaponCheck;

public:
    Item (/*int id,*/ const string& name,const string& desc, int weight, float value);
    Item(const Item &i);
    virtual Item* clone ()const {
        return new Item(*this);
    }
    virtual ~Item();
    string getName();
    string getDesc();
    virtual string toString();
	int getWeight();
	void setWeight(int weightGrams);
    int getValue();
    void setValue(int value);
    //int getWeaponCheck();
    //void setWeaponCheck(int weaponCheck);
};

#endif /*ITEM_H_*/
