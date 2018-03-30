#ifndef TEXT_PARTICLE_H
#define TEXT_PARTICLE_H

#include <string>

class TextParticle
{
    public:
        int x, y, dX, dY, life, r, g, b;
        std::string text;

        TextParticle(){};

        void set(int x, int y, int dX, int dY, int life, std::string text, int r, int g, int b);
    private:
};

#endif
