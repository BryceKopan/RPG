#include "DamageSource.h"

DamageSource::DamageSource()
{
    minDamage = 0;
    maxDamage = 0;
    bonusDamage = 0;
    armorPen = 0;
    accuracy = 0;
}

DamageSource::DamageSource(int minDamage, int maxDamage, int bonusDamage,int armorPen, int accuracy)
{
    this->minDamage = minDamage;
    this->maxDamage = maxDamage;
    this->bonusDamage = bonusDamage;
    this->armorPen = armorPen;
    this->accuracy = accuracy;
}
