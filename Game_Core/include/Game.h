#ifndef GAME_H
#define GAME_H
#include <string>
#include "Window.h"

namespace Game_Core {

	//Enum of possible game states.
	enum GameState {
		Menu, NextLevel, Settings, Running, GameOver, QuitGame, NoState
	};

	class AbstractFactory;

	//State machine keeping & switching the game states.
	class Game {
		public:
			Game(AbstractFactory* factory);
			~Game();
			void Run();
		private:
			AbstractFactory* factory;
			Window* window;
			GameState state;
			std::string username;
			int score;
			int difficulty;
			int lives;
	};
}
#endif

