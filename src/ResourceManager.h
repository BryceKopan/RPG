#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <unordered_map>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <string>

class ResourceManager
{
    public:
        static ALLEGRO_BITMAP* loadBitmap(std::string spritePath); 
        static ALLEGRO_FONT* loadFont(std::string fontPath, int size);
    private:
        static std::unordered_map<std::string, ALLEGRO_BITMAP*> spriteMap;
        static std::unordered_map<std::string, ALLEGRO_FONT*> fontMap;
        static std::string debugID;
};

#endif
