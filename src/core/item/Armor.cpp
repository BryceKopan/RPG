#include "Armor.h"

Armor::Armor(std::string name, Slot slot, int armor, int dodge) :
    Equipment(name, slot)
{
    this->armor = armor;
    this->dodge = dodge;
}

bool Armor::equip(Agent agent)
{
    for(int i = 0; i < agent.equipment.size(); i++)
    {
        if(agent.equipment.at(i)->slot == slot)
        {
            return false;
        }
    }

    agent.armor += armor;
    agent.dodge += dodge;
    agent.equipment.push_back(this);
    equipped = true;

    return true;
}

void Armor::unequip(Agent agent)
{
    for(int i = 0; i < agent.equipment.size(); i++)
    {
        if(this == agent.equipment.at(i))
        {
            agent.equipment.erase(agent.equipment.begin() + i);
            agent.armor -= armor;
            agent.dodge -= dodge;
            equipped = false;
        }
    }
}
