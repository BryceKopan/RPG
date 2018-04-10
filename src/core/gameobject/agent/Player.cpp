#include "Player.h"

#include "../../../managers/GameManager.h"
#include "../../../managers/ResourceManager.h"

Player::Player(int x, int y, int z, int health) :
    Agent(x, y, z, health)
{
    Sprite sprite(ResourceManager::loadBitmap("res/dungeon1.png"), 96, 192);
    this->sprite = sprite;

    equippedWeapon = new Weapon("", weapon, 1, 4, 0, 0, 0);
}

void Player::onDeath()
{
    GameManager::isRunning = false;
}
