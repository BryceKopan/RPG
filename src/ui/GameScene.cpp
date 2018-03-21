#include "GameScene.h"
#include "TextElement.h"
#include "../ResourceManager.h"
#include "../GameManager.h"
#include <sstream>
#include "../GameState.h"

GameScene::GameScene()
{
    ALLEGRO_FONT* font1 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 72);
    int screenWidth = GameManager::SCREEN_WIDTH;

    elements.push_back(new TextElement(25, 0, font1, al_map_rgb(0, 255, 0), ALLEGRO_ALIGN_LEFT));

    elements.push_back(new TextElement(screenWidth - 26, 0, font1, al_map_rgb(255, 255, 255), ALLEGRO_ALIGN_RIGHT));
}

void GameScene::draw()
{
    for(int i = 0; i < elements.size(); i++)
    {
        elements.at(i)->draw();
    }
}

void GameScene::update()
{
    GameState* gameState = GameState::instance;
    std::ostringstream stream;

    TextElement* textElement = static_cast<TextElement*>(elements.at(0));
    stream.str("");
    
    stream << gameState->player->currentHealth << "/" << gameState->player->maxHealth; 

    textElement->text = stream.str();

    textElement = static_cast<TextElement*>(elements.at(1));
    stream.str("");

    stream << gameState->turnNumber;

    textElement->text = stream.str();
}

void GameScene::processInput(ALLEGRO_EVENT event)
{
}
