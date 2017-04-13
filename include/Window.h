#ifndef WINDOW_H
#define WINDOW_H
class Window{
    public:
        const int logical_width=200;
        const int logical_height=200;
        int screen_width;
        int screen_height;
        Window();
        Window(int screen_width, int screen_height);
        virtual ~Window();
        virtual int CreateWindow()=0;
        virtual void PrepareRender()=0;
        virtual void PresentRender()=0;
};
#endif
