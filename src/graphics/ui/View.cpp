#include "View.h"

View::~View()
{
    for(int i = 0; i < elements.size(); i++)
    {
        delete elements.at(i);
    }
}
