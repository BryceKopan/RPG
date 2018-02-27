#ifndef AGENT_H
#define AGENT_H

#include "GameObject.h"
#include "Attributes.h"

class Agent : public GameObject
{
    public:
        int currentHealth, maxHealth, regenTime;
        int hitChance = 75, armor = 0, dodge = 0, currentXP = 0, nextLevelXP = 50, attributePoints = 0, level = 1;
        DamageSource damageSource;
        Attributes attributes;

        Agent(int x, int y, int z, int maxHealth, DamageSource damageSource);

        void move(int dX, int dY);
        bool attacked(Attack attack);
        void update();
    private:
};

#endif
