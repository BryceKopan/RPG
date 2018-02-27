#include "Agent.h"
#include "Chunk.h"
#include "../GameState.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <cmath>

Agent::Agent (int x, int y, int z, int maxHealth, DamageSource damageSource) :
    GameObject(x, y, z, true)
{
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->damageSource = damageSource;
    attributes = Attributes();
}

bool Agent::attacked(Attack attack)
{
    std::ostringstream text;

    //reset regen time
    regenTime = 0;

    //Process Attack
    attack.hitChance -= ((dodge + attributes.dexMod) * 5);

    if(rand() % 100 < hitChance)
    {
        attack.damage -= attack.damage * ((armor * 5) / 100);
        currentHealth -= attack.damage;
        text << attack.damage;
    }
    else
    {
        text << "miss";
    }

    //Create particle that shows damage
    GameState::instance->textPool.addParticle(
            location.x * 64 + 32, 
            location.y * 64 - 32, 
            0, -1, 100, 
            text.str().c_str(), 
            255, 0, 0);

    if(currentHealth <= 0)
    {
        return true;
    }
    else
    {
        return false;
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

        Attack attack(damageSource, hitChance, attributes);

        if(chunk->logicMap.map[location.x + dX][location.y + dY]->
                attacked(attack))
        {
            currentXP += 10;
        }
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

    if (currentXP >= nextLevelXP)
    {
        level++;
        nextLevelXP = std::pow(nextLevelXP, 1.1);
        if(level % 2 == 0)
            attributePoints ++;

        if(level % 5 == 0)
            attributes.globalStatIncrease();

        maxHealth += level + attributes.tghMod;
        currentHealth = maxHealth;
    }
}
