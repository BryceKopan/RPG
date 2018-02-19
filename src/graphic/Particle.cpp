#include "Particle.h"

Particle::Particle()
{
    x = 0;
    y = 0;
    dX = 0;
    dY = 0;
    life = 0;
    type = 0;
}

void Particle::set(int x, int y, int dX, int dY, int life, int type)
{
    this->x = x;
    this->y = y;
    this->dX = dX;
    this->dY = dY;
    this->life = life;
    this->type = type;
}
