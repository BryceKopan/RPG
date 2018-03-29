#include "TextElement.h"

TextElement::TextElement(int x, int y, ALLEGRO_FONT* font, ALLEGRO_COLOR color, int flag) :
    UIElement(x, y)
{
    this->font = font;
    this->color = color;
    this->flag = flag;
}

void TextElement::draw()
{
    al_draw_text(font, color, x, y, flag, text.c_str());
}
