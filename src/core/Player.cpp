#include "Player.h"

Player::Player(int x, int y, int z) :
    GameObject(x-1, y-1, z, true)
{
    sprite = al_load_bitmap("res/Player.png");
}
