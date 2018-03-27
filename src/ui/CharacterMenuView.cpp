#include "CharacterMenuView.h"
#include "TextElement.h"
#include "../ResourceManager.h"
#include "../GameManager.h"
#include "../GameState.h"
#include "RectangleElement.h"

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

    update();
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
}

void CharacterMenuView::processInput(ALLEGRO_EVENT event)
{
}
