#include "GameView.h"

#include "TextElement.h"
#include "CharacterMenuView.h"
#include "InventoryMenuView.h"
#include "../../managers/GameManager.h"
#include "../../managers/LogicManager.h"
#include "../../managers/ResourceManager.h"
#include "../../core/GameState.h"

GameView::GameView()
{
    ALLEGRO_FONT* font1 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 72);
    int screenWidth = GameManager::SCREEN_WIDTH;

    elements.push_back(new TextElement(25, 0, font1, al_map_rgb(0, 255, 0), ALLEGRO_ALIGN_LEFT));

    elements.push_back(new TextElement(screenWidth - 25, 0, font1, al_map_rgb(255, 255, 255), ALLEGRO_ALIGN_RIGHT));
}

void GameView::draw()
{
    for(int i = 0; i < elements.size(); i++)
    {
        elements.at(i)->draw();
    }
}

void GameView::update()
{
    GameState* gameState = GameState::instance;

    std::string text = std::to_string(gameState->player->currentHealth) + "/" + std::to_string(gameState->player->maxHealth);
    TextElement* textElement = static_cast<TextElement*>(elements.at(0));
    textElement->text = text;

    text = std::to_string(gameState->turnNumber);
    textElement = static_cast<TextElement*>(elements.at(1));
    textElement->text = text;
}

void GameView::processInput(ALLEGRO_EVENT event)
{
    GameState* gameState = GameState::instance;

    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {    
        switch(event.keyboard.keycode)
        {
            //Utility Input
            case ALLEGRO_KEY_F7:
                gameState->debugMode = true;
                printf("DebugMode activated \n");
                break;

            case ALLEGRO_KEY_ESCAPE:
                GameManager::isRunning = false;
                break;

            case ALLEGRO_KEY_X:
                delete gameState->currentView;
                gameState->currentView = new CharacterMenuView(); 
                break;

            case ALLEGRO_KEY_I:
                delete gameState->currentView;
                gameState->currentView = new InventoryMenuView();
                break;

            case ALLEGRO_KEY_L:
                gameState->player->currentXP += 100;
                break;

                //Numpad Movement
            case ALLEGRO_KEY_PAD_7:
                gameState->player->move(-1, -1); 
                LogicManager::step();
                break;

            case ALLEGRO_KEY_PAD_8:
                gameState->player->move(0, -1);
                LogicManager::step();
                break;

            case ALLEGRO_KEY_PAD_9:
                gameState->player->move(1, -1); 
                LogicManager::step();
                break;

            case ALLEGRO_KEY_PAD_4:
                gameState->player->move(-1, 0); 
                LogicManager::step();
                break;

            case ALLEGRO_KEY_PAD_5:
                LogicManager::step();
                break;

            case ALLEGRO_KEY_PAD_6:
                gameState->player->move(1, 0); 
                LogicManager::step();
                break;

            case ALLEGRO_KEY_PAD_1:
                gameState->player->move(-1, 1); 
                LogicManager::step();
                break;

            case ALLEGRO_KEY_PAD_2:
                gameState->player->move(0, 1); 
                LogicManager::step();
                break;

            case ALLEGRO_KEY_PAD_3:
                gameState->player->move(1, 1); 
                LogicManager::step();
                break;
        }
    }
}
