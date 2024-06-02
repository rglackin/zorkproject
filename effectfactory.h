#ifndef EFFECTFACTORY_H
#define EFFECTFACTORY_H
#include<QJsonObject>
#include "magicEffect.h"
enum EffectType{
    HEAL,
    ATK
};
class EffectFactory
{
public:
    EffectFactory();
    static MagicEffect* createEffect(QJsonObject obj);
};

#endif // EFFECTFACTORY_H
