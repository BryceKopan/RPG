#include "Weapon.h"

Weapon::Weapon(std::string name, Slot slot, int minDamage, int maxDamage, int bonusDamage, int armorPen, int accuracy) : 
    Equipment(name, slot)
{
    this->minDamage = minDamage;
    this->maxDamage = maxDamage;
    this->bonusDamage = bonusDamage;
    this->armorPen = armorPen;
    this->accuracy = accuracy;
}

/*bool Weapon::equip(Agent* agent)
{
    for(int i = 0; i < agent->equipment.size(); i++)
    {
        if(agent->equipment.at(i)->slot == slot)
        {
            return false;
        }
    }

    agent->equippedWeapon = this;
    agent->equipment.push_back(this);
    equipped = true;

    return true;
}

void Weapon::unequip(Agent agent)
{
    for(int i = 0; i < agent.equipment.size(); i++)
    {
        if(this == agent.equipment.at(i))
        {
            agent.equipment.erase(agent.equipment.begin() + i);
            agent.damageSource = DamageSource(1, 4, 0, 0, 0);
            equipped = false;
        }
    }
}*/

int Weapon::getDamage()
{
    int damage = rand() % (maxDamage - minDamage + 1) + minDamage;
    damage += bonusDamage;
    return damage;
}
