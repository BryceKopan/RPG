#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "../CONSTANTS.h"
#include <allegro5/allegro5.h>
#include "Tile.h"
#include <unordered_map>

class TileMap
{
    public:
        int tileWidth, tileHeight;
        std::unordered_map<int , Tile> tileSet;

        TileMap(){};
        TileMap(int tileWidth, int tileHeight);

        int map[CHUNK_SIZE][CHUNK_SIZE] = {};      
    private:
};

#endif
