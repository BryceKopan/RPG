#include "DrawManager.h"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <sstream>
#include <iostream>
#include "GameManager.h"
#include "CONSTANTS.h"
#include "ResourceManager.h"

DrawManager::DrawManager()
{
    gameState = GameState::instance;

    font1 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 72);
    font2 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 20);
}

void DrawManager::draw()
{
    //Save Relevent Data
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
    for(int i = 0; i < CHUNK_SIZE; i++)
    {
        for(int k = 0; k < CHUNK_SIZE; k++)
        {
            //Draw TileMap
            al_draw_bitmap(
                    gameState->chunk.tileMap.tileSet.at(gameState->chunk.tileMap.map[i][k]).sprite,
                    i * tileWidth,
                    k * tileHeight,
                    0);

            //Draw LogicMap
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

    //Draw Particles
    for(int i = 0; i < gameState->textPool.particleCount; i++)
    {
        TextParticle text = gameState->textPool.pool[i];

        al_draw_text(
                font1, 
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
    std::ostringstream health;
    std::ostringstream turnNumber;

    health << gameState->player->currentHealth << "/" << gameState->player->maxHealth;

    turnNumber << gameState->turnNumber;

    int i = 0;

    al_draw_text(font1, al_map_rgb(0, 255, 0), 25, i, ALLEGRO_ALIGN_LEFT, health.str().c_str());

    al_draw_text(font1, al_map_rgb(255, 255, 255), 615, i, ALLEGRO_ALIGN_RIGHT, turnNumber.str().c_str());

    //Menu
    if(gameState->menu)
    {
        al_draw_filled_rectangle(90, 90, 
                GameManager::SCREEN_WIDTH - 90, 
                GameManager::SCREEN_HEIGHT - 90, 
                al_map_rgb(255, 255, 255));
        al_draw_filled_rectangle(100, 100, 
                GameManager::SCREEN_WIDTH - 100, 
                GameManager::SCREEN_HEIGHT - 100, 
                al_map_rgb(0, 0, 0));

        std::vector<std::string> menuLines;
        std::ostringstream uiText;

        uiText << "Name: ";
        menuLines.push_back(uiText.str());
        uiText.str("");

        uiText << "Health: " << gameState->player->maxHealth <<
            "/" << gameState->player->currentHealth;
        menuLines.push_back(uiText.str());

        for(int i = 0; i < menuLines.size(); i++)
        {
            al_draw_text(font2, 
                    al_map_rgb(255, 255, 255), 125, 125 + (30 * i),
                    ALLEGRO_ALIGN_LEFT, menuLines.at(i).c_str());
        }
    }
}

