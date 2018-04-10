#ifndef WEAPON_H
#define WEAPON_H

#include "Equipment.h"
#include "Slot.h"

//class Agent;

class Weapon : public Equipment
{
    public:
        int minDamage, maxDamage, bonusDamage, armorPen, accuracy;

        Weapon(std::string name, Slot slot, int minDamage, int maxDamage, int bonusDamage, int armorPen, int accuracy);

        //bool equip(Agent* agent);
        //void unequip(Agent agent);
        int getDamage();
    private:
};

#endif
