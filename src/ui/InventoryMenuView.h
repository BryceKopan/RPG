#ifndef INVENTORY_MENU_VIEW_H
#define INVENTORY_MENU_VIEW_H

#include "View.h"

class InventoryMenuView : public View
{
    public:
        InventoryMenuView();

        void draw();
        void update();
        void processInput(ALLEGRO_EVENT event);
};

#endif
