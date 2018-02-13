#ifndef TMX_PARSER_H
#define TMX_PARSER_H

#include <pugixml.hpp>
#include "../GameState.h"
#include <string>
#include <vector>

class TMXParser
{
    public: 
        TMXParser();

        void parseTMXFile(std::string xmlFilePath, GameState* gameState);
    private:
        std::string debugID = "[TMXParser] ";
};

#endif
