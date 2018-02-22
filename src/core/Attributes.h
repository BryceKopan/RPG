#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

class Attributes
{
    public:
        int strength, dexterity, toughness, intelligence, wisdom, piety;
        int strMod, dexMod, tghMod, intMod, wisMod, pieMod;

        Attributes();
        Attributes(int str, int dex, int tgh, int intt, int wis, int pie);   
    private:
        void setMods();
        int calculateMod(int stat);
};

#endif
