#include "SDLBackground.h"
namespace Game_SDL {

SDLBackground::SDLBackground(SDLContext* context):Background(){
    this->context=context;
    image=context->getTexture("graphics/background.png");
    scrollingOffset=0;
    scrollBounds=new BoundingBox(0,0,200,200);//todo
}
SDLBackground::~SDLBackground(){
	delete scrollBounds;
}

void SDLBackground::Visualise(){
    context->Draw(image, bounds);
    context->Draw(image, scrollBounds);
}
void SDLBackground::Update()
{
    int offset=bounds->getY();
    bounds->setY((double)++offset);
    scrollBounds->setY((double)(bounds->getY()-bounds->getHeight()));
	if (bounds->getY() > bounds->getHeight()) {
		bounds->setY(0);
	}
}
}
