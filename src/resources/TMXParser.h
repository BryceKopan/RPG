#ifndef TMX_PARSER_H
#define TMX_PARSER_H

#include <string>
#include <vector>
#include <pugixml.hpp>

#include "../core/GameState.h"

class TMXParser
{
    public: 
        TMXParser();

        void parseTMXFile(std::string xmlFilePath, GameState* gameState);
    private:
        std::string debugID = "[TMXParser] ";
};

#endif
