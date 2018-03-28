#include "InventoryMenuView.h"
#include "../GameState.h"
#include "TextElement.h"
#include "RectangleElement.h"
#include "../ResourceManager.h"
#include "../GameManager.h"
#include "GameView.h"
#include "CharacterMenuView.h"
#include "../core/Weapon.h"

InventoryMenuView::InventoryMenuView()
{
    ALLEGRO_FONT* font1 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 20);
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);

    elements.push_back(new RectangleElement(90, 90, GameManager::SCREEN_WIDTH - 90, GameManager::SCREEN_HEIGHT - 90, white));

    elements.push_back(new RectangleElement(100, 100, GameManager::SCREEN_WIDTH - 100, GameManager::SCREEN_HEIGHT - 100, black));

    std::vector<Item*> items = GameState::instance->player->items;

    for(int i = 0; i < items.size(); i++)
    {
        elements.push_back(new TextElement(125, 125 + (30 * i), font1, white, ALLEGRO_ALIGN_LEFT));
    }
}

void InventoryMenuView::draw()
{
    for(int i = 0; i < elements.size(); i++)
    {
        elements.at(i)->draw();
    }
}

void InventoryMenuView::update()
{
    int i = 2;

    std::vector<Item*> items = GameState::instance->player->items;
    std::string text;

    for(int k = 0; k < items.size(); k++)
    {
        text = items.at(k)->name;
        TextElement* textElement = static_cast<TextElement*>(elements.at(i));
        textElement->text = text;
        i++;
    }
}

void InventoryMenuView::processInput(ALLEGRO_EVENT event)
{
    GameState* gameState = GameState::instance;

    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        switch(event.keyboard.keycode)
        {
            case ALLEGRO_KEY_ESCAPE:

            case ALLEGRO_KEY_I:
                delete gameState->currentView;
                gameState->currentView = new GameView();
                break;

            case ALLEGRO_KEY_TAB:
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

