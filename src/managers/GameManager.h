#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <allegro5/allegro5.h>

class GameManager
{
    public:
        static bool isRunning;
        static int const SCREEN_WIDTH = 800;
        static int const SCREEN_HEIGHT = 600;

        static void init();
        static void loadGameData();
        static void gameLoop();
        static void shutdown();
    private:
        static const int FPS = 60;

        static ALLEGRO_EVENT_QUEUE* eventQueue;
        static ALLEGRO_TIMER* timer;
        static ALLEGRO_DISPLAY* display;
};

#endif
