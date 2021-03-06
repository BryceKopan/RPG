#ifndef TEXT_ELEMENT_H
#define TEXT_ELEMENT_H

#include <string>
#include <allegro5/allegro_font.h>

#include "UIElement.h"

class TextElement : public UIElement
{
    public:
        std::string text;

        TextElement(int x, int y, ALLEGRO_FONT* font, ALLEGRO_COLOR color, int flag);

        void draw();
    protected:
        ALLEGRO_FONT* font;
        ALLEGRO_COLOR color;
        int flag;
};

#endif
