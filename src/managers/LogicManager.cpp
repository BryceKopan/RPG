#include "LogicManager.h"

#include "GameManager.h"
#include "../core/GameState.h"
#include "../core/world/TileMap.h"   

void LogicManager::step()
{
    GameState* gameState = GameState::instance;

    gameState->player->step();

    for(int i = 0; i < gameState->npcs.size(); i++)
    {
        if(gameState->npcs[i]->currentHealth <= 0)
        {
            gameState->npcs[i]->onDeath();
            gameState->chunk.logicMap.map[gameState->npcs[i]->location.x][gameState->npcs[i]->location.y][0] = NULL;
            delete gameState->npcs[i];
            gameState->npcs.erase(gameState->npcs.begin() + i);

        }
        else
        {
            gameState->npcs[i]->step();
        }
    }

    gameState->turnNumber += 1;

    if(gameState->player->currentHealth == 0)
    {
        GameManager::isRunning = false;
    }
}

void LogicManager::update()
{
    GameState* gameState = GameState::instance;

    gameState->textPool.update();
    gameState->currentView->update();
}
