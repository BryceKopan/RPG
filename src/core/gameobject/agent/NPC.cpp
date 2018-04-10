#include "NPC.h"

#include "../BloodSplat.h"
#include "../../GameState.h"
#include "../../../managers/ResourceManager.h"

NPC::NPC(int x, int y, int z, int health) :
    Agent(x, y, z, health),
    ai(3)
{
    Sprite sprite(ResourceManager::loadBitmap("res/dungeon1.png"), 64, 192);
    this->sprite = sprite;

    equippedWeapon = new Weapon("", weapon, 1, 2, 0, 0, 0);
}

void NPC::step()
{
    Agent::step();
    ai.step(this);
}

void NPC::onDeath()
{
    GameState* gameState = GameState::instance;
    
    gameState->chunk.logicMap.map[location.x][location.y][0] = NULL;
    
    for(int i = 0; i < gameState->agents.size(); i++)
    {
        if(this == gameState->agents[i])
        {
            gameState->agents.erase(gameState->agents.begin() + i);
        }
    }

    Chunk* chunk = &gameState->chunk; 
    
    chunk->logicMap.map[location.x][location.y][1] =
        new BloodSplat(location.x, location.y);
}
