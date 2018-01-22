#include "LogicManager.h"

LogicManager::LogicManager()
{
    GameState::instance = new GameState();

    gameState = GameState::instance;
}

void LogicManager::step()
{
}
