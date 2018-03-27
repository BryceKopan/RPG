#include "InputManager.h"
#include "GameManager.h"
#include <iostream>
#include "core/Weapon.h"
#include "ui/CharacterMenuView.h"
#include "ui/InventoryMenuView.h"
#include "ui/GameView.h"

InputManager::InputManager()
{
    gameState = GameState::instance;
}   

void InputManager::Process (ALLEGRO_EVENT event, LogicManager* logicManager)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {    
        if(!gameState->menuCharacter && !gameState->menuInventory)
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

                case ALLEGRO_KEY_X:
                    gameState->menuCharacter = true;
                    delete gameState->currentView;
                    gameState->currentView = new CharacterMenuView(); 
                    break;

                case ALLEGRO_KEY_I:
                    gameState->menuInventory = true;
                    delete gameState->currentView;
                    gameState->currentView = new InventoryMenuView();
                    break;

                case ALLEGRO_KEY_L:
                    gameState->player->currentXP += 100;
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
        else if(gameState->menuCharacter)
        {
            switch(event.keyboard.keycode)
            {
                case ALLEGRO_KEY_ESCAPE:

                case ALLEGRO_KEY_X:
                    gameState->menuCharacter = false;
                    delete gameState->currentView;
                    gameState->currentView = new GameView();
                    break;

                case ALLEGRO_KEY_TAB:
                    gameState->menuCharacter = false;
                    gameState->menuInventory = true;
                    delete gameState->currentView;
                    gameState->currentView = new InventoryMenuView();
                    break;
            }
            if(gameState->player->attributePoints > 0)
            {
                switch(event.keyboard.keycode)
                {
                    case ALLEGRO_KEY_DOWN:
                        gameState->selectedAttribute ++;
                        if(gameState->selectedAttribute > 5)
                            gameState->selectedAttribute = 0;
                        break;

                    case ALLEGRO_KEY_UP:
                        gameState->selectedAttribute --;
                        if(gameState->selectedAttribute < 0)
                            gameState->selectedAttribute = 5;
                        break;

                    case ALLEGRO_KEY_ENTER:
                        switch(gameState->selectedAttribute)
                        {
                            case 0:
                                gameState->player->attributes.strength++;
                                break;

                            case 1:
                                gameState->player->attributes.dexterity++;
                                break;

                            case 2:
                                gameState->player->attributes.toughness++;
                                break;

                            case 3:
                                gameState->player->attributes.intelligence++;
                                break;

                            case 4:
                                gameState->player->attributes.wisdom++;
                                break;

                            case 5:
                                gameState->player->attributes.piety++;
                                break;
                        }
                        gameState->player->attributePoints--;
                        gameState->player->attributes.setMods();
                        break;
                }
            }
        }
        else if(gameState->menuInventory)
        {
            switch(event.keyboard.keycode)
            {
                case ALLEGRO_KEY_ESCAPE:

                case ALLEGRO_KEY_I:
                    gameState->menuInventory = false;
                    delete gameState->currentView;
                    gameState->currentView = new GameView();
                    break;

                case ALLEGRO_KEY_TAB:
                    gameState->menuInventory = false;
                    gameState->menuCharacter = true;
                    delete gameState->currentView;
                    gameState->currentView = new CharacterMenuView();
                    break;

                case ALLEGRO_KEY_E:
                    Weapon* weapon = static_cast<Weapon*>(gameState->player->items.at(0));
                    weapon->equip(gameState->player);
                    break;
            }
        }
    }
}
