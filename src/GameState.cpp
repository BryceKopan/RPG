#include "GameState.h"
#include "core/NPC.h"

GameState* GameState::instance;

GameState::GameState() :
    chunk(0, 0, 0, 64, 64)
{
    player = new Player(5, 5, 0, 5);
    chunk.logicMap.map[player->location.x][player->location.y] = player; 

    npcs.push_back(new NPC(10, 10, 0, 2));
    chunk.logicMap.map[npcs[0]->location.x][npcs[0]->location.y] =
        npcs[0];
}


