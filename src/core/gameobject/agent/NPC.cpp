#include "NPC.h"

#include "../../../managers/ResourceManager.h"

NPC::NPC(int x, int y, int z, int health) :
    Agent(x, y, z, health, DamageSource(1, 2, 0, 0, 0)),
    ai(3)
{
    Sprite sprite(ResourceManager::loadBitmap("res/dungeon1.png"), 64, 192);

    this->sprite = sprite;
}

void NPC::step()
{
    Agent::step();
    ai.step(this);
}
