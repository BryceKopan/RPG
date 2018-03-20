#include "Tile.h"

Tile::Tile(){}

Tile::Tile(bool collidable, Sprite sprite)
{
    this->collidable = collidable;
    this->sprite = sprite;
}
