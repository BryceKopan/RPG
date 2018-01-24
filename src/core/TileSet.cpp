#include "TileSet.h"
#include <string>

TileSet::TileSet()
{
    tileSprites.push_back(al_load_bitmap("res/Floor.png"));
    tileSprites.push_back(al_load_bitmap("res/Wall.png"));
}

ALLEGRO_BITMAP* TileSet::getTileSprite(int i)
{
    return tileSprites[i];
}
