#include "LogicMap.h"

LogicMap::~LogicMap()
{
    for(int i = 0; i < CHUNK_SIZE; i++)
    {
        for(int j = 0; j < CHUNK_SIZE; j++)
        {
            for(int k = 0; k < depth; k++)
            {
                delete map[i][j][k];
            }
        }
    }
}
