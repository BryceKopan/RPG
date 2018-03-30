#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

class Attributes
{
    public:
        int strength = 10, dexterity = 10, toughness = 10, 
            intelligence = 10, wisdom = 10, piety = 10;
        int strMod, dexMod, tghMod, intMod, wisMod, pieMod;

        Attributes();
        Attributes(int str, int dex, int tgh, int intt, int wis, int pie);   

        void globalStatIncrease();
        void setMods();
    private:
        int calculateMod(int stat);
};

#endif
