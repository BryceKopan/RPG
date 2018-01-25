#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <allegro5/allegro5.h>
#include "GameState.h" 

class InputManager
{
    public:
        InputManager();
        void Process(ALLEGRO_EVENT);
    
    private:
        GameState *gameState;

        void movePlayer(int dX, int dY);
};

#endif
