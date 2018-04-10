#ifndef ARMOR_H
#define ARMOR_H

#include "Equipment.h"

class Armor : public Equipment
{
    public:
        int armor, dodge;

        Armor(std::string name, Slot slot, int armor, int dodge);

        //bool equip(Agent agent);
        //void unequip(Agent agent);
    private:
};

#endif
