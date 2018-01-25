#include "GameState.h"

GameState* GameState::instance;

GameState::GameState() :
    chunk(0, 0, 0, 64, 64)
{
    player = new Player(5, 5, 0);
    chunk.logicMap.map[player->location.x][player->location.y] = player; 
}


