#include "Sprite.h"

Sprite::Sprite(){}

Sprite::Sprite(ALLEGRO_BITMAP* spriteSheet, int spriteSheetX, int spriteSheetY)
{
    this->spriteSheet = spriteSheet;
    this->spriteSheetX = spriteSheetX;
    this->spriteSheetY = spriteSheetY;
}
