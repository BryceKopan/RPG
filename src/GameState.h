#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "core/Chunk.h"
#include "core/Player.h"
#include <vector>
#include "core/NPC.h"

class GameState
{
    public:
        static GameState* instance;
        Chunk chunk; 
        std::vector<NPC*> npcs;
        Player* player;
        bool debugMode = false;

        GameState();
    private:
};

#endif
