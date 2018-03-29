#include "TileMap.h"

TileMap::TileMap(int tileWidth, int tileHeight)
{
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    std::unordered_map<int, Tile> tileSet;
}
