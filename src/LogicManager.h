#ifndef LOGICMANAGER_H
#define LOGICMANAGER_H

#include "GameState.h"

class LogicManager
{
    public:
        LogicManager();

        void step();
    private:
        GameState *gameState;
};

#endif

