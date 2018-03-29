#include "TextParticle.h"

TextParticle::TextParticle()
{
    x = 0;
    y = 0;
    dX = 0;
    dY = 0;
    life = 0;
    text = "";
    r = 0;
    g = 0;
    b = 0;
}

void TextParticle::set(int x, int y, int dX, int dY, int life, std::string text, int r, int g, int b)
{
    this->x = x;
    this->y = y;
    this->dX = dX;
    this->dY = dY;
    this->life = life;
    this->text = text;
    this->r = r;
    this->g = g;
    this->b = b;
}
