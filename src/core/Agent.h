#ifndef AGENT_H
#define AGENT_H

#include "GameObject.h"
#include "../CONSTANTS.h"

class Agent : public GameObject
{
    public:
        Agent(int x, int y, int z);

        void move(int dX, int dY, GameObject* map[CHUNK_SIZE][CHUNK_SIZE]);
    private:
};

#endif
