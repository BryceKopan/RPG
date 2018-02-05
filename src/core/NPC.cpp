#include "NPC.h"

NPC::NPC(int x, int y, int z, int health) :
    Agent( x, y, z, health)
{
    ai = AI();
    sprite = al_load_bitmap("res/NPC.png");
}
