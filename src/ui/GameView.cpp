#include "GameView.h"
#include "TextElement.h"
#include "../ResourceManager.h"
#include "../GameManager.h"
#include "../GameState.h"

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
    textElement->text = std::to_string(gameState->player->currentHealth) + "/" + std::to_string(gameState->player->maxHealth);

    text = std::to_string(gameState->turnNumber);
    textElement = static_cast<TextElement*>(elements.at(1));
    textElement->text = text;
}

void GameView::processInput(ALLEGRO_EVENT event)
{
}
