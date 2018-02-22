#include "Attributes.h"

Attributes::Attributes()
{
    strength = 10;
    dexterity = 10;
    toughness = 10;
    intelligence = 10;
    wisdom = 10;
    piety = 10;

    setMods();
}

Attributes::Attributes(int str, int dex, int tgh, int intt, int wis, int pie)
{
    strength = str;
    dexterity = dex;
    toughness = tgh;
    intelligence = intt;
    wisdom = wis;
    piety = pie;

    setMods();
}

void Attributes::setMods()
{
    strMod = calculateMod(strength);
    dexMod = calculateMod(dexterity);
    tghMod = calculateMod(toughness);
    intMod = calculateMod(intelligence);
    wisMod = calculateMod(wisdom);
    pieMod = calculateMod(piety);
    
}

int Attributes::calculateMod(int stat)
{
    if(stat >= 10)
    {
        return (stat - 10) / 2;
    }
    else
    {
        return (11 - stat) / -2;
    }
}
