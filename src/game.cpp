#include "managers/GameManager.h"
#include "resources/TMXParser.h"

int main(int argc, char **argv)
{   
    GameManager::init();
    GameManager::loadGameData();
    GameManager::gameLoop();
    GameManager::shutdown();
    
    return 0;
}


