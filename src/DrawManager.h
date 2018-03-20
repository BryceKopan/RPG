#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "GameState.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class DrawManager
{
    public:
        DrawManager();
        void draw();
    private:
        GameState *gameState; 
        ALLEGRO_TRANSFORM transform;
        ALLEGRO_FONT* font1,* font2,* font3;
};

#endif
