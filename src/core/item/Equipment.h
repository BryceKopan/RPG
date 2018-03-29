#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Item.h"
#include "../gameobject/agent/Agent.h"

class Agent;

enum Slot {head, chest, legs, weapon};

class Equipment : public Item
{
    public:
        bool equipped;
        Slot slot;

        Equipment(std::string name, Slot slot);

        virtual bool equip(Agent* agent) = 0;
        virtual void unequip(Agent agent) = 0;
    private:
};

#endif
