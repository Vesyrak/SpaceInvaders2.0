#ifndef SDLBACKGROUND_H
#define SDLBACKGROUND_H
#include "Background.h"
#include "SDLContext.h"

class SDLBackground: public Background{
	    private:
        SDL_Texture* image;
        SDLContext* context;
        int scrollingOffset;
    public:
	SDLBackground(SDLContext* context);
        ~SDLBackground();
        void Visualise() override;
        void Update() override;
        BoundingBox* scrollBounds;
};
#endif

