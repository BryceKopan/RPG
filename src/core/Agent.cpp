#include "Agent.h"
#include "Chunk.h"
#include "../GameState.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>

Agent::Agent (int x, int y, int z, int maxHealth, DamageSource damageSource) :
    GameObject(x, y, z, true)
{
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->damageSource = damageSource;
    attributes = Attributes();
}

void Agent::attacked(DamageSource damageSource, int hitChance)
{
    //reset regen time
    regenTime = 0;

    //Calculate and apply hitchance, damage
    int damage = 0;

    hitChance += (damageSource.accuracy * 5)
        - ((dodge + attributes.dexMod) * 5);

    if(rand() % 100 < hitChance)
    {
        damage = rand() % 
            (damageSource.maxDamage - damageSource.minDamage + 1) + 
            damageSource.minDamage;
        damage += damageSource.bonusDamage;
        damage -= damage * ((armor * 5) / 100);

        currentHealth -= damage;
    } 

    //Create particle that shows damage
    std::ostringstream text;

    if(damage == 0)
    {
        text << "miss";
    }
    else
    {
        text << damage;
    }

    GameState::instance->textPool.addParticle(location.x * 64 + 32, location.y * 64 - 32, 0, -1, 100, text.str().c_str(), 255, 0, 0);
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

        DamageSource attack = damageSource;
        attack.accuracy += attributes.dexMod;
        attack.bonusDamage += attributes.strMod;

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

void Agent::update()
{
    regenTime++;

    if(regenTime == 6 - attributes.tghMod && currentHealth < maxHealth)
    {
        currentHealth++;
        regenTime = 0;
    }
}
