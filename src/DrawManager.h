#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "GameState.h"
#include "core/TileSet.h"
#include "allegro5/allegro5.h"

class DrawManager
{
    public:
        DrawManager();
        void draw();
    private:
        GameState *gameState;
        TileSet tileSet;
        ALLEGRO_TRANSFORM transform;
};

#endif
