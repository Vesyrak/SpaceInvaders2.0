#ifndef SDLFACTORY_H
#define SDLFACTORY_H
#include "AbstractFactory.h"
#include "SDLPlayerShip.h"
#include "SDLBasher.h"
#include "SDLBlaster.h"
#include "SDLBomber.h"
#include "SDLWindow.h"
#include "SDLInput.h"
#include "SDLContext.h"
#include "SDLBackground.h"
#include "SDLText.h"
#include "SDLLaser.h"
#include "SDLMenu.h"
#include "SDLTimer.h"
#include "SDLText.h"
#include "SDLLaserBomb.h"
#include "SDLHealthbar.h"
#include "SDLGameOverScreen.h"
#include "SDLSettingsScreen.h"
#include "SDLAudioEngine.h"
#include "SDLNextLevelScreen.h"
#include "SDLLifePowerUp.h"
using namespace Game_Core;

namespace Game_SDL {
	class SDLFactory: public AbstractFactory {
		public:
			SDLFactory();
			~SDLFactory() override;
			Basher* CreateBasher(std::vector<Entity*>* bulletVector, int x, int y, int difficulty) override;
			Blaster* CreateBlaster(std::vector<Entity*>* bulletVector, int x, int y, int difficulty) override;
			Bomber* CreateBomber(std::vector<Entity*>* bulletVector, int x, int y, int difficulty) override;
			PlayerShip* CreatePlayerShip(std::vector<Entity*>* bulletVector, int lives, int x, int y, int movementSpeed) override;
			Laser* CreateLaser(int x, int y, int movementSpeed, InputType direction, int damage) override;
			LaserBomb* CreateLaserBomb(int x, int y, int movementSpeed, InputType direction, int damage) override;
	        LifePowerUp* CreateLifePowerUp(PlayerShip* playerShip, int x, int y);
			AudioEngine* GetAudioEngine() override;
			Input* GetInputHandler() override;
			Timer* CreateTimer() override;
			Background* CreateBackground() override;
			Healthbar* CreateHealthbar(Entity* observed, int x, int y) override;
			Text* CreateText(std::string message, int x, int y) override;
			Text* CreateText(std::string message, int x, int y, int size) override;
			Screen* CreateMenu(Window* window) override;
			Screen* CreateSettingsScreen(Window* window, std::string* username) override;
			Screen* CreateNextLevelScreen(int difficulty, Window* window) override;
			Screen* CreateGameOverScreen(std::string username, int score, Window* window) override;
			Window* CreateWindow(int screen_width, int screen_height) override;
		private:
			AudioEngine* audioEngine;
			Input* inputHandler;
			SDLContext* context;
	};
}
#endif

