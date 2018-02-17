#include "InputManager.h"
#include "GameManager.h"
#include <iostream>

InputManager::InputManager()
{
    gameState = GameState::instance;
}   

void InputManager::Process (ALLEGRO_EVENT event, LogicManager* logicManager)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {    
        switch(event.keyboard.keycode)
        {
            //Utility Input
            case ALLEGRO_KEY_F7:
                gameState->debugMode = true;
                std::cout << "DebugMode activated \n";
                break;
            
            case ALLEGRO_KEY_ESCAPE:
                GameManager::isRunning = false;
                break;

            //Numpad Movement
            case ALLEGRO_KEY_PAD_7:
                gameState->player->move(-1, -1); 
                logicManager->step();
                break;
                
            case ALLEGRO_KEY_PAD_8:
                gameState->player->move(0, -1);
                logicManager->step();
                break;
                
            case ALLEGRO_KEY_PAD_9:
                gameState->player->move(1, -1); 
                logicManager->step();
                break;

            case ALLEGRO_KEY_PAD_4:
                gameState->player->move(-1, 0); 
                logicManager->step();
                break;
                
            case ALLEGRO_KEY_PAD_5:
                logicManager->step();
                break;

            case ALLEGRO_KEY_PAD_6:
                gameState->player->move(1, 0); 
                logicManager->step();
                break;

            case ALLEGRO_KEY_PAD_1:
                gameState->player->move(-1, 1); 
                logicManager->step();
                break;

            case ALLEGRO_KEY_PAD_2:
                gameState->player->move(0, 1); 
                logicManager->step();
                break;

            case ALLEGRO_KEY_PAD_3:
                gameState->player->move(1, 1); 
                logicManager->step();
                break;
        }
    }
}
