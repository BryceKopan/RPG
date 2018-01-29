#include "Player.h"

Player::Player(int x, int y, int z) :
    Agent(x-1, y-1, z)
{
    sprite = al_load_bitmap("res/Player.png");
}
