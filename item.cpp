#include "item.h"

Item::Item (/*int id,*/ const string& name,const string& desc, int weight, float value/**, int weaponCheck*/)
    : /*id(id),*/ name(name),desc(desc),weight(weight),value(value) {}

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
