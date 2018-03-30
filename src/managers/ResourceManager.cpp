#include "ResourceManager.h"

#include <allegro5/allegro_ttf.h>

std::unordered_map<std::string, ALLEGRO_BITMAP*> ResourceManager::spriteMap;
std::unordered_map<std::string, ALLEGRO_FONT*> ResourceManager::fontMap;

std::string ResourceManager::debugID = "[ResourceManager] ";

ALLEGRO_BITMAP* ResourceManager::loadBitmap(std::string spritePath)
{
    if(spriteMap.find(spritePath) == spriteMap.end())
    {
        ALLEGRO_BITMAP* bitmap = al_load_bitmap(spritePath.c_str()); 

        if(!bitmap)
        {
            printf("Sprite not found\n");
            bitmap = al_load_bitmap("res/ErrorTexture.png");
        }

        spriteMap[spritePath] = bitmap;
    }

    return spriteMap[spritePath];
}

ALLEGRO_FONT* ResourceManager::loadFont(std::string fontPath, int size)
{
    std::string hashPath = fontPath + std::to_string(size);

    if(fontMap.find(hashPath) == fontMap.end())
    {
        ALLEGRO_FONT* font = al_load_ttf_font(fontPath.c_str(), size, 0); 

        if(!font)
        {
            printf("Font not found\n");
        }

        fontMap[hashPath] = font;
    }

    return fontMap[hashPath];
}
