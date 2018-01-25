#ifndef CHUNK_H
#define CHUNK_H

#include "TileMap.h"
#include "LogicMap.h"
#include "Location.h"

class Chunk
{
    public:
        TileMap tileMap;
        LogicMap logicMap;
        Location location;

        Chunk(int x, int y, int z, int tileWidth, int tileHeight);
    private:
};

#endif
