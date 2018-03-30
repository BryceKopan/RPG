#include "Attributes.h"

Attributes::Attributes()
{
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

void Attributes::globalStatIncrease()
{
    strength++;
    dexterity++;
    toughness++;
    intelligence++;
    wisdom++;
    piety++;
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
