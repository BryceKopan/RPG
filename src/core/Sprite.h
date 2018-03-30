#ifndef SPRITE_H
#define SPRITE_H

#include <allegro5/allegro5.h>

class Sprite
{
    public:
        ALLEGRO_BITMAP* spriteSheet;
        int spriteSheetX, spriteSheetY;

        Sprite(){};
        Sprite(ALLEGRO_BITMAP* spriteSheet);
        Sprite(ALLEGRO_BITMAP* spriteSheet, int spriteSheetX, int spriteSheetY);
    private:
};

#endif
