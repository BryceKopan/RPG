#ifndef AGENT_H
#define AGENT_H

#include <vector>

#include "Attributes.h"
#include "../GameObject.h"
#include "../../item/Item.h"
#include "../../item/Equipment.h"
#include "../../item/Weapon.h"

class Equipment;

class Agent : public GameObject
{
    public:
        int currentHealth, maxHealth, regenTime;
        int hitChance = 75, armor = 0, dodge = 0, currentXP = 0, nextLevelXP = 50, attributePoints = 0, level = 1;
        Attributes attributes;
        std::vector<Item*> items;
        std::vector<Equipment*> equipment;
        Weapon* equippedWeapon;

        Agent(int x, int y, int z, int maxHealth);

        void move(int dX, int dY);
        void attack(Agent* agent);
        virtual void step();
        virtual void onDeath(){};
        void equip(Weapon* weapon);
};

#endif
