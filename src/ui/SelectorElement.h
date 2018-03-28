#ifndef SELECTOR_ELEMENT_H
#define SELECTOR_ELEMENT_H

#include "TextElement.h"
#include <allegro5/allegro_font.h>

class SelectorElement : public TextElement
{
    public:
        int index = 0;

        SelectorElement(int x, int y, ALLEGRO_FONT* font, ALLEGRO_COLOR color, int flag, int maxIndex, int deltaY);

        void draw();
        void changeIndex(int deltaIndex);
    private:
        int maxIndex, deltaY;
};
#endif
