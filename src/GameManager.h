#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>


namespace GameManager
{
    extern bool done;

    void init();
    void gameLoop();
    void shutdown();
}

#endif
