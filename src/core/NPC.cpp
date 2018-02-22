#include "NPC.h"
#include "../ResourceManager.h"

NPC::NPC(int x, int y, int z, int health) :
    Agent(x, y, z, health, DamageSource(1, 2, 0, 0, 0)),
    ai(3)
{
    sprite = ResourceManager::loadBitmap("res/NPC.png");
}

void NPC::update()
{
    Agent::update();
    ai.step(this);
}
