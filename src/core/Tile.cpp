#include "Tile.h"
#include <iostream>
#include "../ResourceManager.h"

Tile::Tile(bool collidable, std::string spritePath)
{
    this->collidable = collidable;
    sprite = ResourceManager::loadBitmap(spritePath.c_str());

    if(!sprite)
    {
        std::cout << "asdasd";
    }
}
