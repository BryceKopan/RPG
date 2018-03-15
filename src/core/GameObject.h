#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Location.h"
#include <allegro5/allegro5.h>
#include "Attack.h"
#include <string>

class GameObject
{
    public:
        Location location;
        bool collidable;
        ALLEGRO_BITMAP* sprite;
        std::string name;

        GameObject(int x, int y, int z, bool collidable);

        virtual bool attacked(Attack Attack){};
    private:
};

#endif
