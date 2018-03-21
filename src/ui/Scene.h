#ifndef SCENE_H
#define SCENE_H

#include <allegro5/allegro5.h>
#include <vector>
#include "UIElement.h"

class Scene
{
    public:
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void processInput(ALLEGRO_EVENT event) = 0;
    protected:
        std::vector<UIElement*> elements;
};

#endif
