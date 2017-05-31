#include <SDL2/SDL.h>
#include "SDLInput.h"
namespace Game_SDL {

	SDLInput::SDLInput() {
	}
	SDLInput::~SDLInput() {

	}

	BaseInput* SDLInput::GetInput() {
		BaseInput* input = new BaseInput();
		SDL_Event event;
		SDL_PollEvent(&event);
		const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL);
		if(currentKeyStates[SDL_SCANCODE_ESCAPE]){
			input->inputVector.push_back(InputType::Quit);
		}
		if (currentKeyStates[SDL_SCANCODE_W]) {
			input->inputVector.push_back(InputType::Up);
		}
		if (currentKeyStates[SDL_SCANCODE_S]) {
			input->inputVector.push_back(InputType::Down);
		}
		if (currentKeyStates[SDL_SCANCODE_A]) {
			input->inputVector.push_back(InputType::Left);
		}
		if (currentKeyStates[SDL_SCANCODE_D]) {
			input->inputVector.push_back(InputType::Right);

		}
		if (currentKeyStates[SDL_SCANCODE_SPACE]) {
			input->inputVector.push_back(InputType::A);

		}
		if (currentKeyStates[SDL_SCANCODE_J]) {
			input->inputVector.push_back(InputType::B);

		}
		if (currentKeyStates[SDL_SCANCODE_K]) {
			input->inputVector.push_back(InputType::X);

		}
		if (currentKeyStates[SDL_SCANCODE_L]) {
			input->inputVector.push_back(InputType::Y);

		}
		if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
			SDL_GetMouseState(&input->mouseX, &input->mouseY);
			if (event.type == SDL_MOUSEBUTTONDOWN)
				input->mousepress = true;
		}
		return input;
	}
	BaseInput* SDLInput::GetInput(std::string* string) {
		BaseInput* input = new BaseInput();
		SDL_Event event;
		SDL_PollEvent(&event);
		const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL);
		if(currentKeyStates[SDL_SCANCODE_ESCAPE]){
			input->inputVector.push_back(InputType::Quit);
		}
		if (currentKeyStates[SDL_SCANCODE_W]) {
			input->inputVector.push_back(InputType::Up);
		}
		if (currentKeyStates[SDL_SCANCODE_S]) {
			input->inputVector.push_back(InputType::Down);
		}
		if (currentKeyStates[SDL_SCANCODE_A]) {
			input->inputVector.push_back(InputType::Left);
		}
		if (currentKeyStates[SDL_SCANCODE_D]) {
			input->inputVector.push_back(InputType::Right);

		}
		if (currentKeyStates[SDL_SCANCODE_SPACE]) {
			input->inputVector.push_back(InputType::A);

		}
		if (currentKeyStates[SDL_SCANCODE_J]) {
			input->inputVector.push_back(InputType::B);

		}
		if (currentKeyStates[SDL_SCANCODE_K]) {
			input->inputVector.push_back(InputType::X);

		}
		if (currentKeyStates[SDL_SCANCODE_L]) {
			input->inputVector.push_back(InputType::Y);

		}
		if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
			SDL_GetMouseState(&input->mouseX, &input->mouseY);
			if (event.type == SDL_MOUSEBUTTONDOWN)
				input->mousepress = true;
		}
		if (event.type == SDL_KEYDOWN) {
			//Handle backspace
			if (event.key.keysym.sym == SDLK_BACKSPACE && string->length() > 0) {
				//lop off character
				string->pop_back();
			}
		}
		if (event.type == SDL_TEXTINPUT) {
			//Append character
			string->append(event.text.text);
		}
		return input;
	}

}
