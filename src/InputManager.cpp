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
            gameState->player->move(0, -1, &gameState->chunk); 
        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_A)
        {
            gameState->player->move(-1, 0, &gameState->chunk); 
        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_S)
        {
            gameState->player->move(0, 1, &gameState->chunk); 
        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_D)
        {
            gameState->player->move(1, 0, &gameState->chunk); 
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            GameManager::done = true;
        }
    }
}
