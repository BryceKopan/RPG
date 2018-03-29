#include "LogicMap.h"

LogicMap::LogicMap()
{
}

LogicMap::~LogicMap()
{
    for(int i = 0; i < CHUNK_SIZE; i++)
    {
        for(int k = 0; k < CHUNK_SIZE; k++)
        {
            delete map[i][k][0];
            delete map[i][k][1];
        }
    }
}
