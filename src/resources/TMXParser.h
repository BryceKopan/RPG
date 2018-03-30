#ifndef TMX_PARSER_H
#define TMX_PARSER_H

#include <string>

class TMXParser
{
    public: 
        static void parseTMXFile(std::string xmlFilePath);
    private:
        static const std::string debugID;
};

#endif
