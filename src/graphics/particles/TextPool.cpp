#include "TextPool.h"

#include <iostream>

TextPool::TextPool()
{
    for(int i = 0; i < POOL_SIZE; i++)
    {
        pool[i] = TextParticle();
    }
}

void TextPool::update()
{
    for(int i = 0; i < particleCount; i++)
    {
        if(pool[i].life > 0)
        {
            pool[i].x += pool[i].dX;
            pool[i].y += pool[i].dY;
            pool[i].life --;
        }
        else
        {
            particleCount--;
            if(i != particleCount)
            {
                pool[i] = pool[particleCount];
                i --;
            }
        }
    }
}

void TextPool::addParticle(int x, int y, int dX, int dY, int life, std::string text, int r, int g, int b)
{
    if(particleCount == POOL_SIZE)
    {
        std::cout << debugID << "Pool full. Cannot add particle\n";
    }
    else
    {
        pool[particleCount].set(x, y, dX, dY, life, text, r, g, b);
        particleCount ++;
    }

}
