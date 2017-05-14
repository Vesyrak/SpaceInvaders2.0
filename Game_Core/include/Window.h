#ifndef WINDOW_H
#define WINDOW_H
#include "BoundingBox.h"
namespace Game_Core {

class Window{
    public:
        const int LOGICAL_WIDTH=200;
        const int LOGICAL_HEIGHT=200;
        int screen_width;
        int screen_height;
        Window();
        Window(int screen_width, int screen_height);
        virtual ~Window();
        virtual int CreateWindow()=0;
        virtual void PrepareRender()=0;
        virtual void PresentRender()=0;
        BoundingBox* getTopBounds();
        BoundingBox* getBottomBounds();
        BoundingBox* getLeftBounds();
        BoundingBox* getRightBounds();
    protected:
        BoundingBox* topBounds;
        BoundingBox* bottomBounds;
        BoundingBox* leftBounds;
        BoundingBox* rightBounds;

};}
#endif
