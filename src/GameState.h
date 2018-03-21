#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "core/Chunk.h"
#include "core/Player.h"
#include <vector>
#include "core/NPC.h"
#include "graphic/TextPool.h"
#include "ui/Scene.h"

class GameState
{
    public:
        static GameState* instance;
        Chunk chunk; 
        std::vector<NPC*> npcs;
        Player* player;
        bool debugMode = false, menuCharacter = false, menuInventory = false;
        int turnNumber = 0, selectedAttribute = 0;
        TextPool textPool;
        Scene* currentScene;

        GameState();
    private:
};

#endif
