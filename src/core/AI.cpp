#include "AI.h"
#include "../GameState.h"
#include "Player.h"

AI::AI()
{
}

void AI::step(Agent* aiAgent)
{
    Player player = *GameState::instance->player;

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
    else if(player.location.x < aiAgent->location.x &&
            player.location.y == aiAgent->location.y)
    {
        aiAgent->move(1,0);
    }
    
}
