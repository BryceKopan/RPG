#include "DrawManager.h"
#include "GameManager.h"
#include "CONSTANTS.h"
#include <iostream>

DrawManager::DrawManager()
{
    gameState = GameState::instance;
}

void DrawManager::draw()
{
    int playerX = gameState->player->location.x;
    int playerY = gameState->player->location.y;
    int tileWidth = gameState->chunk.tileMap.tileWidth;
    int tileHeight = gameState->chunk.tileMap.tileHeight;

    al_identity_transform(&transform);
    al_translate_transform(&transform, 
            (-(playerX + 1) * tileWidth) +
            (GameManager::SCREEN_WIDTH / 2) + (tileWidth / 2),
            (-(playerY + 1) * tileWidth) + 
            (GameManager::SCREEN_HEIGHT / 2) + (tileHeight / 2));
    al_use_transform(&transform);

    for(int i = 0; i < CHUNK_SIZE; i++)
    {
        for(int k = 0; k < CHUNK_SIZE; k++)
        {
            al_draw_bitmap(
                    gameState->chunk.tileMap.tileSet.at(gameState->chunk.tileMap.map[i][k]).sprite,
                    i * tileWidth,
                    k * tileHeight,
                    0);

            if(gameState->chunk.logicMap.map[i][k] != NULL)
            {
                al_draw_bitmap(
                        gameState->chunk.logicMap.map[i][k]->sprite,
                        i * tileWidth,
                        k * tileHeight,
                        0);
            }
        }
    }
}

