#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "../core/GameState.h"

class DrawManager
{
    public:
        static void init();
        static void draw();
    private:
        //static ALLEGRO_TRANSFORM transform;
        //static ALLEGRO_FONT* font1,* font2,* font3;
};

#endif
