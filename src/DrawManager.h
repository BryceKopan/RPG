#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "GameState.h"
#include "core/TileSet.h"

class DrawManager
{
    public:
        DrawManager();
        void draw();
    private:
        GameState *gameState;
        TileSet tileSet;
};

#endif
