#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include <allegro5/allegro5.h>

#include "UIElement.h"

class View
{
    public:
        ~View();

        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void processInput(ALLEGRO_EVENT event) = 0;
    protected:
        std::vector<UIElement*> elements;
};

#endif
