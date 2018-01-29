#ifndef AGENT_H
#define AGENT_H

#include "GameObject.h"
#include "Chunk.h"

class Agent : public GameObject
{
    public:
        Agent(int x, int y, int z);

        void move(int dX, int dY, Chunk* chunk);
    private:
};

#endif
