#ifndef CHARACTER_MENU_VIEW_H
#define CHARACTER_MENU_VIEW_H

#include "View.h"

class CharacterMenuView : public View
{
    public:
        CharacterMenuView();

        void draw();
        void update();
        void processInput(ALLEGRO_EVENT event);
};

#endif
