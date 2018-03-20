#include "Agent.h"
#include "Chunk.h"
#include "../GameState.h"
#include "BloodSplat.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <cmath>
#include "Weapon.h"

Agent::Agent (int x, int y, int z, int maxHealth, DamageSource damageSource) :
    GameObject(x, y, z, true)
{
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->damageSource = damageSource;
    attributes = Attributes();
    items.push_back(new Weapon("Sword", weapon, DamageSource(10,10,10,10,10)));
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

    int tileWidth = GameState::instance->chunk.tileMap.tileWidth;
    int tileHeight = GameState::instance->chunk.tileMap.tileHeight;

    //Create particle that shows damage
    GameState::instance->textPool.addParticle(
            (location.x * tileWidth) + (tileWidth / 2), 
            (location.y * tileHeight) - (tileHeight / 2), 
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
    else if(chunk->logicMap.map[location.x + dX][location.y + dY][0] != NULL)
    {
        if(GameState::instance->debugMode == true)
        {
            std::cout << "Agent Attacking \n";
        }

        Attack attack(damageSource, hitChance, attributes);

        if(chunk->logicMap.map[location.x + dX][location.y + dY][0]->
                attacked(attack))
        {
            currentXP += 10;
        }
    }
    else
    {
        chunk->logicMap.map[location.x + dX][location.y + dY][0] = 
            chunk->logicMap.map[location.x][location.y][0];
        chunk->logicMap.map[location.x][location.y][0] = NULL;

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

void Agent::killed()
{
    Chunk* chunk = &GameState::instance->chunk; 
    
    chunk->logicMap.map[location.x][location.y][1] =
        new BloodSplat(location.x, location.y);
}
