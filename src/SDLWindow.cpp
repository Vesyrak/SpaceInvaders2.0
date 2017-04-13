#include <iostream>
#include "SDLWindow.h"

SDLWindow::SDLWindow():Window(){

}
SDLWindow::SDLWindow( int screen_width, int screen_height):Window(screen_width,screen_height){

}
SDLWindow::~SDLWindow(){

    //SDL_FreeSurface(Surface_Display);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    std::cout << "Deleted Window" << std::endl;

}
int SDLWindow::CreateWindow(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    else{
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            std::cout<<"Warning: Linear texture filtering not enabled!"<<std::endl;
        }
        window = SDL_CreateWindow("Yo Whadup", 100, 100, screen_width, screen_height, SDL_WINDOW_SHOWN);
        if (window == NULL){
            std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }
        else{
            renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(renderer==NULL){
                std::cout<<"Renderer could not be created!: "<< SDL_GetError()<<std::endl;
                return 1;
            }
            else{
                PrepareRender();
                int imgFlags=IMG_INIT_PNG;
                if(!(IMG_Init(imgFlags) & imgFlags)){
                    std::cout<<"SDL_Image could not initialize! Error: "<< IMG_GetError()<<std::endl;
                    return 1;
                }
            }

        }
    }
    SDL_RenderSetLogicalSize(renderer, screen_width, screen_height);
    return 0;
}

void SDLWindow::PresentRender(){
    SDL_RenderPresent(renderer);
}

void SDLWindow::PrepareRender(){
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

}

