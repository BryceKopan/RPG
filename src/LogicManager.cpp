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
    for(int i = 0; i < gameState->npcs.size(); i++)
    {
        if(gameState->debugMode == true)
        {
            std::cout << "Stepping agent " << i << "\n";
            std::cout << "Agent " << i << " health is " <<
                gameState->npcs[i]->health << "\n";
        }  

        if(gameState->npcs[i]->health == 0)
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
            gameState->npcs[i]->ai.step(gameState->npcs[i]);
        }
    }

    if(gameState->player->health == 0)
    {
        GameManager::isRunning = false;
    }
}
