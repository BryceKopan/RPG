#ifndef PARTICLE_POOL_H
#define PARTICLE_POOL_H

#include "Particle.h"
#include <string>

const int POOL_SIZE = 10;

class ParticlePool
{
    public:
        Particle pool[POOL_SIZE];
        int particleCount = 0;

        ParticlePool();
        
        void update();
        void addParticle(int x, int y, int dX, int dY, int life, int type);
    private:
        const std::string debugID = "[ParticlePool] ";
};

#endif
