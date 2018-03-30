#include "Weapon.h"

Weapon::Weapon(std::string name, Slot slot, DamageSource damageSource) : 
    Equipment(name, slot)
{
    this->damageSource = damageSource;
}

bool Weapon::equip(Agent* agent)
{
    for(int i = 0; i < agent->equipment.size(); i++)
    {
        if(agent->equipment.at(i)->slot == slot)
        {
            return false;
        }
    }

    agent->damageSource = damageSource;
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
}
