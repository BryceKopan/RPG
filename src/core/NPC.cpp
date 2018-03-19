#include "NPC.h"
#include "../ResourceManager.h"

NPC::NPC(int x, int y, int z, int health) :
    Agent(x, y, z, health, DamageSource(1, 2, 0, 0, 0)),
    ai(3)
{
    Sprite sprite(ResourceManager::loadBitmap("res/dungeon1.png"), 0, 0);

    this->sprite = sprite;
}

void NPC::update()
{
    Agent::update();
    ai.step(this);
}
