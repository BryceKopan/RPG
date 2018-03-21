#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

class UIElement
{
    public:
        UIElement(int x, int y);

        virtual void draw();
    protected:
        int x, y;
    private:
};

#endif
