#ifndef PARTICLE_H
#define PARTICLE_H

class Particle
{
    public:
        int x, y, dX, dY, life, type;

        Particle();

        void set(int x, int y, int dX, int dY, int life, int type);
    private:
};

#endif
