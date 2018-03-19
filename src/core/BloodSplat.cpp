#include "BloodSplat.h"
#include "../ResourceManager.h"

BloodSplat::BloodSplat(int x, int y) : 
    GameObject(x , y, 0, false)
{
    Sprite sprite(ResourceManager::loadBitmap("res/BloodSplat.png"), 0, 0);
    this->sprite = sprite;
}
