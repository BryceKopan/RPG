#include "InputManager.h"

#include "../core/GameState.h"

void InputManager::Process (ALLEGRO_EVENT event)
{
    GameState* gameState = GameState::instance;

    gameState->currentView->processInput(event);
}
