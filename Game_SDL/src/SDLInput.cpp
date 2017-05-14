#include <SDL2/SDL.h>
#include "SDLInput.h"
namespace Game_SDL {

SDLInput::SDLInput() {
}
SDLInput::~SDLInput() {

}
void SDLInput::getCharacterInput(std::string* text) {
    SDL_StartTextInput();
	//Handle events on queue
	SDL_Event e;
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_KEYDOWN) {
			//Handle backspace
			if (e.key.keysym.sym == SDLK_BACKSPACE && text->length() > 0) {
				//lop off character
				text->pop_back();
			}
		}
		if (e.type == SDL_TEXTINPUT) {
			//Append character
			text->append( e.text.text);
		}
	}
    SDL_StopTextInput();
}

std::vector<InputType> SDLInput::getInput() {
	std::vector<InputType> input;
	SDL_PollEvent(&event);
	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL);

	if (currentKeyStates[SDL_SCANCODE_W]) {
		input.push_back(InputType::Up);
	}
	if (currentKeyStates[SDL_SCANCODE_S]) {
		input.push_back(InputType::Down);
	}
	if (currentKeyStates[SDL_SCANCODE_A]) {
		input.push_back(InputType::Left);
	}
	if (currentKeyStates[SDL_SCANCODE_D]) {
		input.push_back(InputType::Right);

	}
	if (currentKeyStates[SDL_SCANCODE_SPACE]) {
		input.push_back(InputType::A);

	}
	if (currentKeyStates[SDL_SCANCODE_J]) {
		input.push_back(InputType::B);

	}
	if (currentKeyStates[SDL_SCANCODE_K]) {
		input.push_back(InputType::X);

	}
	if (currentKeyStates[SDL_SCANCODE_L]) {
		input.push_back(InputType::Y);

	}

	return input;
}
}
