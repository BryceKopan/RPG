#include "ResourceManager.h"
#include "iostream"

std::unordered_map<std::string, ALLEGRO_BITMAP*> ResourceManager::hashMap;

ALLEGRO_BITMAP* ResourceManager::loadBitmap(const std::string spritePath)
{
    if(hashMap.find(spritePath) == hashMap.end())
    {
        hashMap[spritePath] = al_load_bitmap(spritePath.c_str());    
    }

    return hashMap[spritePath];
}
