#include "item.h"

Item::Item (const string& name,const string& desc, int weight, float value/**, int weaponCheck*/)
    : name(name),desc(desc),weight(weight),value(value) {}
//copy constructor
Item::Item(Item &i){
    name = i.name;
    desc = i.desc;
    weight = i.weight;
    value = i.value;
};
void Item::setWeight(int inWeightGrams)
{
    weight = inWeightGrams;
}

void Item::setValue(int inValue)
{
    value = inValue;
}

string Item::getName()
{
    return name;
}

string Item::getDesc()
{
    return desc;
}

int Item::getValue(){
    return value;
}
//void Item::use(){}
