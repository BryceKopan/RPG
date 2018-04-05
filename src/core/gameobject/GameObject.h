#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>

#include "agent/Attack.h"
#include "../Sprite.h"
#include "../Location.h"

class GameObject
{
    public:
        Location location;
        bool collidable;
        Sprite sprite;
        std::string name;

        GameObject(int x, int y, int z, bool collidable);

        virtual void attacked(Attack Attack){};
};
#endif
