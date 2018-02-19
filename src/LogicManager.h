#ifndef LOGICMANAGER_H
#define LOGICMANAGER_H

#include "GameState.h"

class LogicManager
{
    public:
        LogicManager();

        void step();
        void update();
    private:
        GameState *gameState;
};

#endif

