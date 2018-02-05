#ifndef AGENT_H
#define AGENT_H

#include "GameObject.h"

class Agent : public GameObject
{
    public:
        int health;

        Agent(int x, int y, int z, int health);

        void move(int dX, int dY);
        void attacked(int damage);
    private:
};

#endif
