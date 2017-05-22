#ifndef GAME_H
#define GAME_H
#include "AbstractFactory.h"
#include "PlayerShip.h"
#include "Input.h"
#include "Level.h"
namespace Game_Core {
	enum GameState {
		Menu, NextLevel, Settings, Running, GameOver, QuitGame
	};
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

