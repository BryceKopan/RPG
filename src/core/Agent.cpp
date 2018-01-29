#include "Agent.h"

Agent::Agent (int x, int y, int z) :
    GameObject(x-1, y-1, z, true)
{
}

void Agent::move(int dX, int dY, Chunk* chunk)
{
    if(chunk->tileMap.map[location.x + dX][location.y + dY] == 1)
    {    
    }
    else if(chunk->logicMap.map[location.x + dX][location.y + dY] != NULL)
    {
    }
    else
    {
        chunk->logicMap.map[location.x + dX][location.y + dY] = 
            chunk->logicMap.map[location.x][location.y];
        chunk->logicMap.map[location.x][location.y] = NULL;

        location.x += dX;
        location.y += dY;
    }
}
