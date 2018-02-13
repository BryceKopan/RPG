#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <allegro5/allegro5.h>
#include "GameState.h" 
#include "LogicManager.h"

class InputManager
{
    public:
        InputManager();
        void Process(ALLEGRO_EVENT, LogicManager* logicManager);
    private:
        GameState *gameState;
};

#endif
