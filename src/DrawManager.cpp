#include "DrawManager.h"
#include "GameManager.h"
#include "CONSTANTS.h"
#include <iostream>
#include <allegro5/allegro_ttf.h>
#include <sstream>

DrawManager::DrawManager()
{
    gameState = GameState::instance;

    font = al_load_ttf_font("res/fonts/merienda/Merienda-Regular.ttf", 72, 0);

    if(!font)
    {
        std::cout << "Error loading font\n";
    }

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

    al_identity_transform(&transform);
    al_use_transform(&transform);

    std::ostringstream health;
    std::ostringstream turnNumber;

    health << gameState->player->currentHealth << "/" << gameState->player->maxHealth;

    turnNumber << gameState->turnNumber;

    int i = 0;

    al_draw_text(font, al_map_rgb(0, 225, 0), 25, i, ALLEGRO_ALIGN_LEFT, health.str().c_str());

    al_draw_text(font, al_map_rgb(255, 225, 225), 615, i, ALLEGRO_ALIGN_RIGHT, turnNumber.str().c_str());
}

