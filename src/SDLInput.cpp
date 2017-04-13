#include <SDL2/SDL.h>
#include "SDLInput.h"
SDLInput::SDLInput(){
}
std::vector<InputType> SDLInput::getInput(){
    std::vector<InputType> input;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_a:
                    input.push_back(InputType::Left);
                    break;
                case SDLK_d:
                    input.push_back(InputType::Right);
                    break;
                case SDLK_s:
                    input.push_back(InputType::Down);
                    break;
                case SDLK_w:
                    input.push_back(InputType::Up);
                    break;
                case SDLK_SPACE:
                    input.push_back(InputType::A);
                    break;
                case SDLK_j:
                    input.push_back(InputType::B);
                    break;
                case SDLK_k:
                    input.push_back(InputType::X);
                    break;
                case SDLK_l:
                    input.push_back(InputType::Y);
                    break;
            }
            break;
    }
    return input;
}
