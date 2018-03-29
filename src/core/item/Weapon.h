#ifndef WEAPON_H
#define WEAPON_H

#include "Equipment.h"
#include "../gameobject/agent/DamageSource.h"

class Weapon : public Equipment
{
    public:
        DamageSource damageSource;

        Weapon(std::string name, Slot slot, DamageSource damageSource);

        bool equip(Agent* agent);
        void unequip(Agent agent);
    private:
};

#endif
