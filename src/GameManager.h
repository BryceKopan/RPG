#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>


namespace GameManager
{
    extern bool done;
    int const SCREEN_WIDTH = 640;
    int const SCREEN_HEIGHT = 480;

    void init();
    void gameLoop();
    void shutdown();
}

#endif
