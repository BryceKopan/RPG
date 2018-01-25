#ifndef LOGIC_MAP_H
#define LOGIC_MAP_H

#include "../CONSTANTS.h"
#include "GameObject.h"

class LogicMap
{
    public:
        GameObject* map[CHUNK_SIZE][CHUNK_SIZE] = {{NULL}};

        LogicMap();
        ~LogicMap();
    private:
};

#endif
