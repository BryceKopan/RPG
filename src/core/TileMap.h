#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "../CONSTANTS.h"
#include <allegro5/allegro5.h>
#include <vector>
#include "Tile.h"

class TileMap
{
    public:
        int tileWidth, tileHeight;
        std::vector<Tile> tileSet;

        TileMap(){};
        TileMap(int tileWidth, int tileHeight);

        int map[CHUNK_SIZE][CHUNK_SIZE] = {};      
    private:
};

#endif
