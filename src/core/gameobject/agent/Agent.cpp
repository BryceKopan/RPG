#include "Agent.h"

#include <cmath>
#include <stdlib.h>

#include "../../GameState.h"
#include "../../world/Chunk.h"

Agent::Agent (int x, int y, int z, int maxHealth) :
    GameObject(x, y, z, true)
{
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    attributes = Attributes();
    items.push_back(new Weapon("Sword", weapon, 10,10,10,10,10));
}

void Agent::attack(Agent* agent)
{
    GameState* gameState = GameState::instance;
    std::string text;
    int hitChance, damage;

    //reset regen time
    agent->regenTime = 0;

    //calculate hit chance
    hitChance = this->hitChance;
    hitChance -= ((agent->dodge + agent->attributes.dexMod) * 5);
    hitChance += ((equippedWeapon->accuracy + attributes.dexMod) * 5);

    if(rand() % 100 < hitChance)
    {
        //calculate damage
        //armorPen not taken into account
        damage = equippedWeapon->getDamage();
        damage -= damage * ((agent->armor * 5) / 100);

        agent->currentHealth -= damage;
        text = std::to_string(damage);
    }
    else
    {
        text = "miss";
    }

    int tileWidth = GameState::instance->chunk.tileMap.tileWidth;
    int tileHeight = GameState::instance->chunk.tileMap.tileHeight;

    //Create particle that shows damage
    GameState::instance->textPool.addParticle(
            (agent->location.x * tileWidth) + (tileWidth / 2), 
            (agent->location.y * tileHeight) - (tileHeight / 2), 
            0, -1, 100, 
            text, 
            255, 0, 0);

    if(agent->currentHealth <= 0)
    {
        gameState->deadAgents.push_back(agent);
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
        Agent* agent = static_cast<Agent*>(chunk->logicMap.map[location.x + dX][location.y + dY][0]);
        attack(agent);
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

void Agent::step()
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

void Agent::equip(Weapon* weapon)
{
    for(int i = 0; i < equipment.size(); i++)
    {
        if(equipment.at(i)->slot == weapon->slot)
        {
            return;
        }
    }

    equippedWeapon = weapon;
    equipment.push_back(weapon);
    weapon->equipped = true;
}
