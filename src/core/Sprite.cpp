#include "Sprite.h"

Sprite::Sprite(ALLEGRO_BITMAP* spriteSheet)
{
    this->spriteSheet = spriteSheet;
    spriteSheetX = 0;
    spriteSheetY = 0;
}

Sprite::Sprite(ALLEGRO_BITMAP* spriteSheet, int spriteSheetX, int spriteSheetY)
{
    this->spriteSheet = spriteSheet;
    this->spriteSheetX = spriteSheetX;
    this->spriteSheetY = spriteSheetY;
}
