#ifndef RECTANGLE_ELEMENT_H
#define RECTANGLE_ELEMENT_H

#include <allegro5/allegro_primitives.h>

#include "UIElement.h"

class RectangleElement : public UIElement
{
    public:
        RectangleElement(int x, int y, int width, int height, ALLEGRO_COLOR color);

        void draw();
    private:
        ALLEGRO_COLOR color;
        int width, height;
};
#endif
