#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>

#include "world/Chunk.h"
#include "gameobject/agent/Agent.h"
#include "gameobject/agent/Player.h"
#include "../graphics/ui/View.h"
#include "../graphics/particles/TextPool.h"

class GameState
{
    public:
        static GameState* instance;
        Chunk chunk; 
        std::vector<Agent*> agents;
        std::vector<Agent*> deadAgents;
        Player* player;
        bool debugMode = false;
        int turnNumber = 0;
        TextPool textPool;
        View* currentView;

        GameState();
    private:
};

#endif
