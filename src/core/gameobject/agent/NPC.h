#ifndef NPC_H
#define NPC_H

#include "AI.h"
#include "Agent.h"

class NPC : public Agent 
{
    public:
        AI ai;

        NPC(int x, int y, int z, int health);

        void step();
    private:
};

#endif
