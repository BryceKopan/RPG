#ifndef AI_H
#define AI_H

#include "Agent.h"

class AI
{
    public:
        int detectionRange;

        AI(int detectionRange);

        void step(Agent* aiAgent);
    private:
};

#endif
