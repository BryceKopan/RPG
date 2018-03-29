#ifndef LOGIC_MAP_H
#define LOGIC_MAP_H

#include "../CONSTANTS.h"
#include "../gameobject/GameObject.h"

class LogicMap
{
    public:
        static const int depth = 2;

        GameObject* map[CHUNK_SIZE][CHUNK_SIZE][depth] = {{{NULL}}};

        LogicMap();
        ~LogicMap();
    private:
};

#endif
