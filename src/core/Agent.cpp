#include "Agent.h"

Agent::Agent (int x, int y, int z) :
    GameObject(x-1, y-1, z, true)
{
}

void Agent::move(int dX, int dY, GameObject* map[CHUNK_SIZE][CHUNK_SIZE])
{
    map[location.x + dX][location.y + dY] = map[location.x][location.y];
    map[location.x][location.y] = NULL;

    location.x += dX;
    location.y += dY;
}
