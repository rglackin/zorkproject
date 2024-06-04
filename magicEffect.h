#ifndef MAGICEFFECT_H
#define MAGICEFFECT_H
//#include "item.h"
#include <string>
using namespace std;
class MagicEffect
{
private:
    int buffAmount;
public:
    MagicEffect(int buffAmount);
    int getBuffAmount() const;
    virtual void applyEffect(class Character& character) const = 0;
    virtual string effectString() =0;
};

#endif // MAGICEFFECT_H
