#ifndef TILE_SET_H
#define TILE_SET_H

#include <allegro5/allegro5.h>
#include <vector>

class TileSet
{
    public:
        TileSet();
        std::vector<ALLEGRO_BITMAP*> tileSprites;

        ALLEGRO_BITMAP* getTileSprite(int i);
    private:
};

#endif
