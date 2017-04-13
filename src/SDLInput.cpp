#include <SDL2/SDL.h>
#include "SDLInput.h"
SDLInput::SDLInput(){
}
std::vector<InputType> SDLInput::getInput(){
	std::vector<InputType> input;
	SDL_PollEvent(&event);
	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

	if( currentKeyStates[ SDL_SCANCODE_W ] )
	{
		input.push_back(InputType::Up);
	}
	else if( currentKeyStates[ SDL_SCANCODE_S ] )
	{
		input.push_back(InputType::Down);
	}
	else if( currentKeyStates[ SDL_SCANCODE_A ] )
	{
		input.push_back(InputType::Left);
	}
	else if( currentKeyStates[ SDL_SCANCODE_D ] )
	{
		input.push_back(InputType::Right);

	}
	 if( currentKeyStates[ SDL_SCANCODE_SPACE ] )
	{
		input.push_back(InputType::A);

	}
	 if( currentKeyStates[ SDL_SCANCODE_J ] )
	{
		input.push_back(InputType::B);

	}
	 if( currentKeyStates[ SDL_SCANCODE_K ] )
	{
		input.push_back(InputType::X);

	}
	 if( currentKeyStates[ SDL_SCANCODE_L ] )
	{
		input.push_back(InputType::Y);

	}

	return input;
}
