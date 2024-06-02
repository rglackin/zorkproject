#include "effectfactory.h"
#include "healEffect.h"
#include "atkEffect.h"
#include <string>
using namespace std ;
EffectType stringToEffect(const string& str) {
    static const std::map<string, EffectType> typeMap = {
        {"atk", EffectType::ATK},
        {"heal", EffectType::HEAL},
    };
    auto it = typeMap.find(str);
    if (it != typeMap.end()) {
        return it->second;
    } else {
        throw invalid_argument("Invalid direction input");
    }
}
EffectFactory::EffectFactory() {}
MagicEffect* EffectFactory::createEffect(QJsonObject obj){
    string typeString = obj["type"].toString().toStdString();
    EffectType type = stringToEffect(typeString);
    int amount = obj["amount"].toInt();
    MagicEffect* effect = nullptr;
    switch(type){
    case HEAL:
        effect= new HealEffect(amount);
        break;
    case ATK:
        effect = new AtkEffect(amount);
        break;
    }
    return effect;
};
