#include "DamageSource.h"

#include <stdlib.h>

DamageSource::DamageSource(int minDamage, int maxDamage, int bonusDamage,int armorPen, int accuracy)
{
    this->minDamage = minDamage;
    this->maxDamage = maxDamage;
    this->bonusDamage = bonusDamage;
    this->armorPen = armorPen;
    this->accuracy = accuracy;
}

int DamageSource::getDamage()
{
    int damage = rand() % (maxDamage - minDamage + 1) + minDamage;
    damage += bonusDamage;
    return damage;
}
