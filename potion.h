#ifndef POTION_H
#define POTION_H
#include <memory>
#include "item.h"
#include "magicEffect.h"
using namespace std;
class Potion:virtual public Item
{
private:
    shared_ptr<MagicEffect> effect;
    int uses;
public:
    Potion(/*int id,*/ const string& name,const string& desc, int weight, float value,MagicEffect* effect, int uses);
    Potion(const Potion &i);
    virtual Potion* clone() const {
        return new Potion(*this);
    }
    void use(class Character& c);
    void decrementUses();

    int getUses() const;
    //void setUses(int newUses);
};

#endif // POTION_H
