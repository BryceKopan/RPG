#include "GameObject.h"

GameObject::GameObject(int x, int y, int z, bool collidable)
{
    this->location = Location(x, y, z);
    this->collidable = collidable;
}
