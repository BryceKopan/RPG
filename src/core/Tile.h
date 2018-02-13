#ifndef TILE_H
#define TILE_H

#include <allegro5/allegro5.h>
#include <string>

class Tile
{
    public:
        ALLEGRO_BITMAP* sprite;
        bool collidable;

        Tile(bool collidable, std::string spritePath);
    private:
};

#endif
