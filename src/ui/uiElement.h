#ifndef UI_ELEMENT
#define UI_ELEMENT

class uiElement
{
    public:
        virtual void draw();
        virtual void update();
    private:
        int x, y;
};

#endif 
