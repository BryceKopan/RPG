#include "LogicManager.h"

#include "GameManager.h"
#include "../core/GameState.h"
#include "../core/world/TileMap.h"   

void LogicManager::step()
{
    GameState* gameState = GameState::instance;

    gameState->player->step();

    for(int i = 0; i < gameState->agents.size(); i++)
    {
        gameState->agents[i]->step();

        for(int j = 0; j < gameState->deadAgents.size(); j++)
        {
            gameState->deadAgents[i]->onDeath();
        }

        gameState->deadAgents.clear();
    }

    gameState->turnNumber += 1;
}

void LogicManager::update()
{
    GameState* gameState = GameState::instance;

    gameState->textPool.update();
    gameState->currentView->update();
}
