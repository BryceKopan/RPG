#include "TMXParser.h"
#include <iostream>
#include "../CONSTANTS.h"
#include "../core/NPC.h"
#include "../core/DamageSource.h"
#include "../ResourceManager.h"

TMXParser::TMXParser()
{
}

void TMXParser::parseTMXFile(std::string xmlFilePath, GameState* gameState)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlFilePath.c_str());

    std::cout << debugID << "Document loading - " << result.description() << "\n";

    pugi::xml_node root = doc.document_element();

    if(root.attribute("width").as_int() != CHUNK_SIZE || 
            root.attribute("height").as_int() != CHUNK_SIZE)
    {
        std::cout << debugID << "TMX map is not 64 x 64" << "\n";
    }

    int tileWidth = root.attribute("tilewidth").as_int();
    int tileHeight = root.attribute("tileheight").as_int();

    if(tileWidth != tileHeight)
    {
        std::cout << debugID << "Warning: Tiles aren't square" << "\n";
    }

    gameState->chunk.tileMap.tileWidth = tileWidth;
    gameState->chunk.tileMap.tileHeight = tileHeight;
    
    pugi::xml_node currentNode = root.child("tileset");

    int tileSetSize = currentNode.attribute("tilecount").as_int();

    currentNode = currentNode.child("image");

    std::string pngFilePath = currentNode.attribute("source").value();

    int spriteSheetWidth = currentNode.attribute("width").as_int() / 
        tileWidth;

    currentNode = currentNode.next_sibling("tile");

    bool collidable;

    for(int i = 0; i < tileSetSize; i++)
    {
        collidable = currentNode.child("properties").child("property").attribute("value").as_int();

        int spriteID = currentNode.attribute("id").as_int();
        int spriteX = (spriteID % spriteSheetWidth) * tileWidth;
        int spriteY = (spriteID / spriteSheetWidth) * tileHeight;

        Sprite sprite(ResourceManager::loadBitmap(pngFilePath),
                spriteX, spriteY);

        Tile tile(collidable, sprite);
        gameState->chunk.tileMap.tileSet[spriteID] = tile;

        currentNode = currentNode.next_sibling("tile");
    }

    if(gameState->chunk.tileMap.tileSet.size() != tileSetSize)
    {
        std::cout << debugID << "TileSet size is unexpected size\n";
    }

    currentNode = root.child("layer").child("data").child("tile");

    int x, y, t;

    for(int k = 0; k < CHUNK_SIZE*CHUNK_SIZE; k++)
    {
        y = k / CHUNK_SIZE;
        x = k % CHUNK_SIZE;
    
        t = currentNode.attribute("gid").as_int();

        if(t == 0)//All empty spots are set to tile 0
        {
            gameState->chunk.tileMap.map[x][y] = 31;
        }
        else
        {
            gameState->chunk.tileMap.map[x][y] = t - 1;
        }

        currentNode = currentNode.next_sibling();
    }

   currentNode = root.child("layer").next_sibling().child("data").child("tile");

    for(int k = 0; k < CHUNK_SIZE*CHUNK_SIZE; k++)
    {
        y = k / CHUNK_SIZE;
        x = k % CHUNK_SIZE;
        
        t = currentNode.attribute("gid").as_int();

        switch(t)
        {
            case 0:
                break;

            case 64:
                gameState->player = new Player(x, y, 0, 10);
                gameState->chunk.logicMap.map[x][y][0] = gameState->player;
                break;

            case 63:
                gameState->npcs.push_back(new NPC(x, y, 0, 5)); 
                gameState->chunk.logicMap.map[x][y][0] = 
                    gameState->npcs.at(gameState->npcs.size() - 1);
                break;    

            defualt:
                std::cout << debugID << "Logic object: " << t << " has not been implemented\n";
                break;
        }

        currentNode = currentNode.next_sibling();
    }
    
    std::cout << debugID << "TMX parsing finished \n";  
}
