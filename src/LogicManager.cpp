#include "LogicManager.h"

#include "core/TileMap.h"

LogicManager::LogicManager()
{
    GameState::instance = new GameState();

    gameState = GameState::instance;
}

void LogicManager::step()
{
}
