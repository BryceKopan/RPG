#include "SelectorElement.h"

SelectorElement::SelectorElement(int x, int y, ALLEGRO_FONT* font, ALLEGRO_COLOR color, int flag, int maxIndex, int deltaY) :
    TextElement(x, y, font, color, flag)
{
    this->maxIndex = maxIndex;
    this->deltaY = deltaY;
}

void SelectorElement::draw()
{
    al_draw_text(font, color, x, y + (deltaY * index), flag, text.c_str());
}

void SelectorElement::changeIndex(int deltaIndex)
{
    index += deltaIndex;

    if(index > maxIndex)
    {
        index = 0;
    }
    else if(index < 0)
    {
        index = maxIndex;
    }
}
