#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <unordered_map>
#include <allegro5/allegro.h>
#include <string>

class ResourceManager
{
    public:
        static ALLEGRO_BITMAP* loadBitmap(const std::string spritePath); 
    private:
        static std::unordered_map<std::string, ALLEGRO_BITMAP*> hashMap;
};

#endif
