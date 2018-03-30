#include "TextParticle.h"

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
