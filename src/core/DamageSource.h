#ifndef DAMAGE_SOURCE_H
#define DAMAGE_SOURCE_H

class DamageSource
{
    public:
        int minDamage, maxDamage, armorPen, accuracy;

        DamageSource();
        DamageSource(int minDamage, int maxDamage, int armorPen, int accuracy);
    private:
};

#endif
