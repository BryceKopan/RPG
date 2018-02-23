#include "Attack.h"

Attack::Attack(DamageSource damageSource, int hitChance, Attributes attributes)
{
    this->damage = damageSource.getDamage() + attributes.strMod;
    this->armorPen = damageSource.armorPen;
    this->hitChance = hitChance + 5 * (damageSource.accuracy + attributes.dexMod);
}
