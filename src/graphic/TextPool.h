#ifndef TEXT_POOL_H
#define TEXT_POOL_H

#include "TextParticle.h"
#include <string>

const int POOL_SIZE = 10;

class TextPool
{
    public:
        TextParticle pool[POOL_SIZE];
        int particleCount = 0;

        TextPool();
        
        void update();
        void addParticle(int x, int y, int dX, int dY, int life, std::string text, int r, int g, int b);
    private:
        const std::string debugID = "[TextPool] ";
};

#endif
