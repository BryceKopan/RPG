#include "BloodSplat.h"

#include "../../managers/ResourceManager.h"

BloodSplat::BloodSplat(int x, int y) : 
    GameObject(x , y, 0, false)
{
    Sprite sprite(ResourceManager::loadBitmap("res/BloodSplat.png"));
    this->sprite = sprite;
}
