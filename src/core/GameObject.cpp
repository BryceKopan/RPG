#include "GameObject.h"

GameObject::GameObject(int x, int y, int z, bool collidable)
{
    this->location = Location(x - 1, y - 1, z);
    this->collidable = collidable;
}
