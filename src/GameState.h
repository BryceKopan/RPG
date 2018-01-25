#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "core/Chunk.h"
#include "core/Player.h"

class GameState
{
    public:
        static GameState* instance;
        Chunk chunk; 
        Player* player;

        GameState();
    private:
};

#endif
