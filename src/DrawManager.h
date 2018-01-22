#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "GameState.h"

class DrawManager
{
    public:
        DrawManager();
        void draw();
    private:
        GameState *gameState;
};

#endif
