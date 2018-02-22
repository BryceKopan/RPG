#include "LogicManager.h"
#include "core/TileMap.h"   
#include "GameManager.h"
#include <iostream>

LogicManager::LogicManager()
{
    gameState = GameState::instance;
}

void LogicManager::step()
{
    gameState->player->update();

    for(int i = 0; i < gameState->npcs.size(); i++)
    {
        if(gameState->debugMode == true)
        {
            std::cout << "Stepping agent " << i << "\n";
            std::cout << "Agent " << i << " health is " <<
                gameState->npcs[i]->currentHealth << "\n";
        }  

        if(gameState->npcs[i]->currentHealth <= 0)
        {
            if(gameState->debugMode == true)
            {
                std::cout << "Destroying Agent " << i << "\n";
            }  

            gameState->chunk.logicMap.map[gameState->npcs[i]->location.x][gameState->npcs[i]->location.y] = NULL;
            delete gameState->npcs[i];
            gameState->npcs.erase(gameState->npcs.begin() + i);
        }
        else
        {
            gameState->npcs[i]->update();
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
    gameState->textPool.update();
}
