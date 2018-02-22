#ifndef AGENT_H
#define AGENT_H

#include "GameObject.h"
#include "Attributes.h"

class Agent : public GameObject
{
    public:
        int currentHealth, maxHealth, regenTime;
        int hitChance = 80, armor = 0, dodge = 0;
        DamageSource damageSource;
        Attributes attributes;

        Agent(int x, int y, int z, int maxHealth, DamageSource damageSource);

        void move(int dX, int dY);
        void attacked(DamageSource damageSource, int hitChance);
        void update();
    private:
};

#endif
