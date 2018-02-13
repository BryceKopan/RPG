#include "GameState.h"
#include "core/NPC.h"

GameState* GameState::instance;

GameState::GameState() :
    chunk(0, 0, 0, 64, 64)
{
}
