#include "DrawManager.h"

#include "GameManager.h"
#include "ResourceManager.h"
#include "../core/CONSTANTS.h"

void DrawManager::draw()
{
    ALLEGRO_FONT* font1 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 72);
    ALLEGRO_FONT* font2 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 20);
    ALLEGRO_FONT* font3 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 40);
    ALLEGRO_TRANSFORM transform;

    GameState* gameState = GameState::instance;

    //Store Relevent Data
    int playerX = gameState->player->location.x;
    int playerY = gameState->player->location.y;
    int tileWidth = gameState->chunk.tileMap.tileWidth;
    int tileHeight = gameState->chunk.tileMap.tileHeight;

    //Set up transform to set camera over player
    al_identity_transform(&transform);
    al_translate_transform(&transform, 
            (-(playerX + 1) * tileWidth) +
            (GameManager::SCREEN_WIDTH / 2) + (tileWidth / 2),
            (-(playerY + 1) * tileWidth) + 
            (GameManager::SCREEN_HEIGHT / 2) + (tileHeight / 2));
    al_use_transform(&transform);

    //Draw Game World
    for(int k = 0; k < CHUNK_SIZE; k++)
    {
        for(int i = 0; i < CHUNK_SIZE; i++)
        {
            //Draw TileMap
            Sprite sprite = gameState->chunk.tileMap.tileSet[gameState->chunk.tileMap.map[i][k]].sprite;

            al_draw_bitmap_region(
                    sprite.spriteSheet,
                    sprite.spriteSheetX,
                    sprite.spriteSheetY,
                    tileWidth,
                    tileHeight,
                    i * tileWidth,
                    k * tileHeight,
                    0);

            //Draw LogicMap
            for(int j = gameState->chunk.logicMap.depth - 1; j >= 0; j--)
            {
                if(gameState->chunk.logicMap.map[i][k][j] != NULL)
                {
                    Sprite sprite = gameState->chunk.logicMap.map[i][k][j]->sprite;

                    al_draw_bitmap_region(
                            sprite.spriteSheet,
                            sprite.spriteSheetX,
                            sprite.spriteSheetY,
                            tileWidth,
                            tileHeight,
                            i * tileWidth,
                            k * tileHeight,
                            0);
                }
            }
        }
    }

    //Draw Particles
    for(int i = 0; i < gameState->textPool.particleCount; i++)
    {
        TextParticle text = gameState->textPool.pool[i];

        al_draw_text(
                font3, 
                al_map_rgb(text.r, text.g, text.b), 
                text.x, 
                text.y, 
                ALLEGRO_ALIGN_CENTER, 
                text.text.c_str());
    }

    //Remove transform
    //Everything after this point x and y limited to screen size
    al_identity_transform(&transform);
    al_use_transform(&transform);

    //Draw UI
    gameState->currentView->draw();
}
