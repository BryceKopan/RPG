#include "AI.h"

#include <math.h>

#include "Player.h"
#include "../../GameState.h"

AI::AI(int detectionRange)
{
    this->detectionRange = detectionRange;
}

void AI::step(Agent* aiAgent)
{
    Player player = *GameState::instance->player;

    if(sqrt(pow(player.location.x - aiAgent->location.x, 2) + 
            pow(player.location.y - aiAgent->location.y, 2)) <= 
            detectionRange)
    {
        if(player.location.x > aiAgent->location.x &&
                player.location.y > aiAgent->location.y)
        {
            aiAgent->move(1,1);
        }
        else if(player.location.x == aiAgent->location.x &&
                player.location.y > aiAgent->location.y)
        {
            aiAgent->move(0,1);
        }
        else if(player.location.x < aiAgent->location.x &&
                player.location.y > aiAgent->location.y)
        {
            aiAgent->move(-1,1);
        }
        else if(player.location.x < aiAgent->location.x &&
                player.location.y == aiAgent->location.y)
        {
            aiAgent->move(-1,0);
        }
        else if(player.location.x < aiAgent->location.x &&
                player.location.y < aiAgent->location.y)
        {
            aiAgent->move(-1,-1);
        }
        else if(player.location.x == aiAgent->location.x &&
                player.location.y < aiAgent->location.y)
        {
            aiAgent->move(0,-1);
        }
        else if(player.location.x > aiAgent->location.x &&
                player.location.y < aiAgent->location.y)
        {
            aiAgent->move(1,-1);
        }
        else if(player.location.x > aiAgent->location.x &&
                player.location.y == aiAgent->location.y)
        {
            aiAgent->move(1,0);
        }
    }
}
