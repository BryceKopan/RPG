#include "Tile.h"
#include <iostream>

Tile::Tile(bool collidable, std::string spritePath)
{
    this->collidable = collidable;
    sprite = al_load_bitmap(spritePath.c_str());

    if(!sprite)
    {
        std::cout << "asdasd";
    }
}
