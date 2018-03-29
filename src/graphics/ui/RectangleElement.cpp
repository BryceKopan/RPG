#include "RectangleElement.h"

RectangleElement::RectangleElement(int x, int y, int width, int height, ALLEGRO_COLOR color) :
    UIElement(x, y)
{
    this->width = width;
    this->height = height;
    this->color = color;
}

void RectangleElement::draw()
{
    al_draw_filled_rectangle(x, y, width, height, color);
}
