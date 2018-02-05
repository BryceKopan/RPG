#include "NPC.h"

NPC::NPC(int x, int y, int z, int health) :
    Agent(x, y, z, health),
    ai(3)
{
    sprite = al_load_bitmap("res/NPC.png");
}
