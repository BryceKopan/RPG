#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Scene.h"

class GameScene : public Scene
{
    public:
        GameScene();

        void draw();
        void update();
        void processInput(ALLEGRO_EVENT event);
    private:
};

#endif
