#include "ParticlePool.h"
#include "iostream"

ParticlePool::ParticlePool()
{
    for(int i = 0; i < POOL_SIZE; i++)
    {
        pool[i] = Particle();
    }
}

void ParticlePool::update()
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

void ParticlePool::addParticle(int x, int y, int dX, int dY, int life, int type)
{
    if(particleCount == POOL_SIZE)
    {
        std::cout << debugID << "Pool full. Cannot add particle\n";
    }
    else
    {
        pool[particleCount].set(x, y, dX, dY, life, type);
        particleCount ++;
    }

}
