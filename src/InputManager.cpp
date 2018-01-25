#include "InputManager.h"
#include "GameManager.h"

InputManager::InputManager()
{
    gameState = GameState::instance;
}   

void InputManager::Process (ALLEGRO_EVENT event)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {    
        if( event.keyboard.keycode == ALLEGRO_KEY_W)
        {
            movePlayer(0, -1);
        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_A)
        {
            movePlayer(-1, 0);
        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_S)
        {
            movePlayer(0, 1);
        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_D)
        {
            movePlayer(1, 0);
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            GameManager::done = true;
        }
    }
}

void InputManager::movePlayer(int dX, int dY)
{
    int playerX = gameState->player->location.x;
    int playerY = gameState->player->location.y;

    gameState->chunk.logicMap.map[playerX + dX][playerY + dY] = 
        gameState->chunk.logicMap.map[playerX][playerY];

    gameState->chunk.logicMap.map[playerX][playerY] = NULL;

    gameState->player->location.x += dX;
    gameState->player->location.y += dY;
}
