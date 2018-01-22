#include "GameManager.h"

int main(int argc, char **argv)
{   
    GameManager::init();
    GameManager::gameLoop();
    GameManager::shutdown();
    
    return 0;
}


