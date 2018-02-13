#include "Agent.h"
#include "../GameState.h"
#include "Chunk.h"
#include <iostream>

Agent::Agent (int x, int y, int z, int health) :
    GameObject(x, y, z, true)
{
    this->health = health;
}

void Agent::attacked(int damage)
{
    health -= damage;
    if(GameState::instance->debugMode == true)
    {
        std::cout << "Agent Attacked for " << damage << " damage\n";
        std::cout << "Agent Health " << 
            health + damage << "->" << health << "\n";
    } 
}

void Agent::move(int dX, int dY)
{
    Chunk* chunk = &GameState::instance->chunk; 

    if(chunk->tileMap.tileSet.at(chunk->tileMap.map[location.x + dX][location.y + dY]).collidable)
    {    
    }
    else if(chunk->logicMap.map[location.x + dX][location.y + dY] != NULL)
    {
        if(GameState::instance->debugMode == true)
        {
            std::cout << "Agent Attacking \n";
        }

        chunk->logicMap.map[location.x + dX][location.y + dY]->attacked(1);
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
