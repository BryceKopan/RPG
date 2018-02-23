#ifndef ATTACK_H
#define ATTACK_H

#include "DamageSource.h"
#include "Attributes.h"

class Attack
{
    public:
        int damage, armorPen, hitChance;

        Attack(DamageSource damageSource, int hitChance, Attributes attributes);
    private:
};

#endif
