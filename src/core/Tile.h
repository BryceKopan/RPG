#ifndef TILE_H
#define TILE_H

#include <string>
#include "Sprite.h"

class Tile
{
    public:
        Sprite sprite;
        bool collidable;

        Tile(bool collidable, Sprite sprite);
    private:
};

#endif
