#include "Player.h"
#include "../ResourceManager.h"

Player::Player(int x, int y, int z, int health) :
    Agent(x, y, z, health, DamageSource(1, 4, 0, 0, 0))
{
    Sprite sprite(ResourceManager::loadBitmap("res/dungeon1.png"), 32, 32);
    this->sprite = sprite;
}
