#include "BloodSplat.h"
#include "../ResourceManager.h"

BloodSplat::BloodSplat(int x, int y) : 
    GameObject(x , y, 0, false)
{
    sprite = ResourceManager::loadBitmap("res/BloodSplat.png");
}
