#ifndef SDLBACKGROUND_H
#define SDLBACKGROUND_H
#include "Background.h"
#include "SDLContext.h"
using namespace Game_Core;
namespace Game_SDL {
class SDLBackground: public Background{
	    private:
        SDL_Texture* image;
        SDLContext* context;
        int scrollingOffset;
        BoundingBox* scrollBounds;
    public:
	SDLBackground(SDLContext* context);
        ~SDLBackground();
        void Visualise() override;
        void Update() override;
};}
#endif

