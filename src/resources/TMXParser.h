#ifndef TMX_PARSER_H
#define TMX_PARSER_H

#include <string>

class TMXParser
{
    public: 
        TMXParser();

        void parseTMXFile(std::string xmlFilePath);
    private:
        std::string debugID = "[TMXParser] ";
};

#endif
