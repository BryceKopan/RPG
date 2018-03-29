#include "Equipment.h"

Equipment::Equipment (std::string name, Slot slot) : Item(name)
{
    equipped = false;
    this->slot = slot;
}
