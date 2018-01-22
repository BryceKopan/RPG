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
        if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            GameManager::done = true;
        }
    }
}



