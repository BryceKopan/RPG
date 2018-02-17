#include "Agent.h"
#include "Chunk.h"
#include "../GameState.h"
#include <iostream>
#include <stdlib.h>

Agent::Agent (int x, int y, int z, int maxHealth, DamageSource damageSource) :
    GameObject(x, y, z, true)
{
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->damageSource = damageSource;
}

void Agent::attacked(DamageSource damageSource, int hitChance)
{
    int damage = 0;

    hitChance += damageSource.accuracy * 5 - dodge * 5;

    std::cout << "HitChance: " << hitChance << "\n";

    if(rand() % 100 < hitChance)
    {
        damage = rand() % 
            (damageSource.maxDamage - damageSource.minDamage + 1) + 
            damageSource.minDamage;

        damage -= damage * ((armor * 5) / 100);

        currentHealth -= damage;

        std::cout << "Damage: " << damage << "Health: " << currentHealth <<"\n";
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

        chunk->logicMap.map[location.x + dX][location.y + dY]->attacked(damageSource, hitChance);
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
