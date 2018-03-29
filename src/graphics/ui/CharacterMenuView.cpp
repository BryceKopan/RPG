#include "CharacterMenuView.h"

#include "TextElement.h"
#include "SelectorElement.h"
#include "RectangleElement.h"
#include "GameView.h"
#include "InventoryMenuView.h"
#include "../../managers/GameManager.h"
#include "../../managers/ResourceManager.h"
#include "../../core/GameState.h"

CharacterMenuView::CharacterMenuView()
{
    ALLEGRO_FONT* font1 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 20);
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);

    elements.push_back(new RectangleElement(90, 90, GameManager::SCREEN_WIDTH - 90, GameManager::SCREEN_HEIGHT - 90, white));

    elements.push_back(new RectangleElement(100, 100, GameManager::SCREEN_WIDTH - 100, GameManager::SCREEN_HEIGHT - 100, black));

    elements.push_back(new TextElement(125, 125, font1, white, ALLEGRO_ALIGN_LEFT));

    elements.push_back(new TextElement(125, 155, font1, white, ALLEGRO_ALIGN_LEFT));
    
    elements.push_back(new TextElement(125, 185, font1, white, ALLEGRO_ALIGN_LEFT));

    elements.push_back(new TextElement(125, 215, font1, white, ALLEGRO_ALIGN_LEFT));

    elements.push_back(new TextElement(125, 245, font1, white, ALLEGRO_ALIGN_LEFT));

    elements.push_back(new TextElement(125, 275, font1, white, ALLEGRO_ALIGN_LEFT));

    elements.push_back(new TextElement(125, 305, font1, white, ALLEGRO_ALIGN_LEFT));

    elements.push_back(new TextElement(125, 335, font1, white, ALLEGRO_ALIGN_LEFT));

    elements.push_back(new TextElement(125, 365, font1, white, ALLEGRO_ALIGN_LEFT));

    elements.push_back(new TextElement(125, 395, font1, white, ALLEGRO_ALIGN_LEFT));

    elements.push_back(new SelectorElement(120, 245, font1, white, ALLEGRO_ALIGN_RIGHT, 5, 30));
}

void CharacterMenuView::draw()
{
    for(int i = 0; i < elements.size(); i++)
    {
        elements.at(i)->draw();
    }
}

void CharacterMenuView::update()
{
    GameState* gameState = GameState::instance;
    Player player = *gameState->player;
    int i = 2;

    std::string text = "Level: " + std::to_string(player.level);
    TextElement* textElement = static_cast<TextElement*>(elements.at(i));
    textElement->text = text;
    i++;

    text = "Health: " + std::to_string(player.currentHealth) + "/" + std::to_string(player.maxHealth);
    textElement = static_cast<TextElement*>(elements.at(i));
    textElement->text = text;
    i++;

    text = "XP: " + std::to_string(player.currentXP) + "/" + std::to_string(player.nextLevelXP);
    textElement = static_cast<TextElement*>(elements.at(i));
    textElement->text = text;
    i++;

    text = "Armor: " + std::to_string(player.armor) + " Dodge: " + std::to_string(player.dodge);
    textElement = static_cast<TextElement*>(elements.at(i));
    textElement->text = text;
    i++;

    text = "Strength: " + std::to_string(player.attributes.strength);
    textElement = static_cast<TextElement*>(elements.at(i));
    textElement->text = text;
    i++;

    text = "Dexterity: " + std::to_string(player.attributes.dexterity);
    textElement = static_cast<TextElement*>(elements.at(i));
    textElement->text = text;
    i++;

    text = "Toughness: " + std::to_string(player.attributes.toughness);
    textElement = static_cast<TextElement*>(elements.at(i));
    textElement->text = text;
    i++;

    text = "Intelligence: " + std::to_string(player.attributes.intelligence);
    textElement = static_cast<TextElement*>(elements.at(i));
    textElement->text = text;
    i++;

    text = "Wisdom: " + std::to_string(player.attributes.wisdom);
    textElement = static_cast<TextElement*>(elements.at(i));
    textElement->text = text;
    i++;

    text = "Piety: " + std::to_string(player.attributes.piety);
    textElement = static_cast<TextElement*>(elements.at(i));
    textElement->text = text;
    i++;

    if(player.attributePoints > 0)
    {
        text = ">";
    }
    else
    {
        text = "";
    }
    textElement = static_cast<TextElement*>(elements.at(i));
    textElement->text = text;
    i++;
}

void CharacterMenuView::processInput(ALLEGRO_EVENT event)
{
    GameState* gameState = GameState::instance;

    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        switch(event.keyboard.keycode)
        {
            case ALLEGRO_KEY_ESCAPE:

            case ALLEGRO_KEY_X:
                delete gameState->currentView;
                gameState->currentView = new GameView();
                break;

            case ALLEGRO_KEY_TAB:
                delete gameState->currentView;
                gameState->currentView = new InventoryMenuView();
                break;
        }
        if(gameState->player->attributePoints > 0)
        {
            SelectorElement* selectorElement = 
                static_cast<SelectorElement*>(elements.at(12));

            switch(event.keyboard.keycode)
            {
                case ALLEGRO_KEY_DOWN:
                    selectorElement->changeIndex(1);
                    break;

                case ALLEGRO_KEY_UP:
                    selectorElement->changeIndex(-1);
                    break;

                case ALLEGRO_KEY_ENTER:
                    switch(selectorElement->index)
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
}
