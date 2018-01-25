#include "Chunk.h"

Chunk::Chunk(int x, int y, int z, int tileWidth, int tileHeight)
{
    this->tileMap = TileMap(tileWidth, tileHeight);
    this->logicMap = LogicMap();
    this->location = Location(x, y, z);
}
