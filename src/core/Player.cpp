#include "Player.h"
#include "../ResourceManager.h"

Player::Player(int x, int y, int z, int health) :
    Agent(x, y, z, health, DamageSource(1, 4, 0, 0))
{
    sprite = ResourceManager::loadBitmap("res/Player.png");
}
