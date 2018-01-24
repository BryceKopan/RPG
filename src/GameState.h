#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "core/TileMap.h"

class GameState
{
    public:
        GameState();

        static GameState* instance;

        TileMap tileMap;
    private:
};

#endif
