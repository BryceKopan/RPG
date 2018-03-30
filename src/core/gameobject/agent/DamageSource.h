#ifndef DAMAGE_SOURCE_H
#define DAMAGE_SOURCE_H

class DamageSource
{
    public:
        int minDamage, maxDamage, bonusDamage, armorPen, accuracy;

        DamageSource(){};
        DamageSource(int minDamage, int maxDamage, int bonusDamage,int armorPen, int accuracy);

        int getDamage();
    private:
};

#endif
