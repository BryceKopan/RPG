#include "DrawManager.h"

DrawManager::DrawManager()
{
    gameState = GameState::instance;
}

void DrawManager::draw()
{
    for(int i = 0; i < gameState->tileMap.mapXSize; i++)
    {
        for(int k = 0; k < gameState->tileMap.mapYSize; k++)
        {
            al_draw_bitmap(tileSet.getTileSprite(gameState->tileMap.map[i][k]),
                    i * gameState->tileMap.tileWidth,
                    k * gameState->tileMap.tileHeight, 0);
        }
    }
}

