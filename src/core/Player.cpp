#include "Player.h"

Player::Player(int x, int y, int z, int health) :
    Agent(x-1, y-1, z, health)
{
    sprite = al_load_bitmap("res/Player.png");
}
