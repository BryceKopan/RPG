#include "InputManager.h"
#include "GameManager.h"
#include <iostream>

InputManager::InputManager()
{
    gameState = GameState::instance;
}   

void InputManager::Process (ALLEGRO_EVENT event)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {    
        if(event.keyboard.keycode == ALLEGRO_KEY_W)
        {
            gameState->player->move(0, -1); 
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_A)
        {
            gameState->player->move(-1, 0); 
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_S)
        {
            gameState->player->move(0, 1); 
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_D)
        {
            gameState->player->move(1, 0); 
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_F7)
        {
            gameState->debugMode = true;
            std::cout << "DebugMode activated \n";
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            GameManager::isRunning = false;
        }
    }
}
