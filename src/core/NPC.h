#ifndef NPC_H
#define NPC_H

#include "Agent.h"
#include "AI.h"

class NPC : public Agent 
{
    public:
        AI ai;

        NPC(int x, int y, int z, int health);
    private:
};

#endif
