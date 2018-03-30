#ifndef AGENT_H
#define AGENT_H

#include <vector>

#include "Attributes.h"
#include "../GameObject.h"
#include "../../item/Item.h"
#include "../../item/Equipment.h"

class Equipment;

class Agent : public GameObject
{
    public:
        int currentHealth, maxHealth, regenTime;
        int hitChance = 75, armor = 0, dodge = 0, currentXP = 0, nextLevelXP = 50, attributePoints = 0, level = 1;
        DamageSource damageSource;
        Attributes attributes;
        std::vector<Item*> items;
        std::vector<Equipment*> equipment;

        Agent(int x, int y, int z, int maxHealth, DamageSource damageSource);

        void move(int dX, int dY);
        bool attacked(Attack attack);
        void step();
        void onDeath();
    private:
};

#endif
