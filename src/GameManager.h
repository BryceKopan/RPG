#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "core/TileMap.h"
#include <iostream>

namespace GameManager
{
    extern bool isRunning;
    int const SCREEN_WIDTH = 640;
    int const SCREEN_HEIGHT = 480;

    void init();
    void loadGameData();
    void gameLoop();
    void shutdown();
}

#endif
