#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "PlayerShip.h"
#include "Basher.h"
#include "Blaster.h"
#include "Bomber.h"
#include "Window.h"
#include "Input.h"
#include "Background.h"
#include "Laser.h"
#include "Timer.h"
#include "Text.h"
#include "Healthbar.h"
#include "LaserBomb.h"
#include "Screen.h"
#include "AudioEngine.h"
namespace Game_Core {
class AbstractFactory {
	public:
		virtual ~AbstractFactory() {
		}
		virtual PlayerShip* createPlayerShip(std::vector<Entity*>* bulletVector, int lives, int x, int y, int movementSpeed)=0;
		virtual Basher* createBasher(std::vector<Entity*>* bulletVector, int x, int y, int movementSpeed)=0;
		virtual Blaster* createBlaster(std::vector<Entity*>* bulletVector, int x, int y, int movementSpeed)=0;
		virtual Bomber* createBomber(std::vector<Entity*>* bulletVector, int x, int y, int movementSpeed)=0;
		virtual Window* createWindow(int screen_width, int screen_height)=0;
		virtual Input* getInputHandler()=0;
		virtual Background* createBackground()=0;
		virtual Laser* createLaser(int x, int y, int movementSpeed, InputType direction, int damage)=0;
		virtual Screen* createMenu(Window* window)=0;
		virtual Timer* createTimer()=0;
		virtual Text* createText(std::string message, int x, int y)=0;
		virtual Text* createText(std::string message, int x, int y, int size)=0;
		virtual LaserBomb* createLaserBomb(int x, int y, int movementSpeed, InputType direction, int damage)=0;
		virtual Healthbar* createHealthbar(Entity* observed, int x, int y)=0;
		virtual Screen* createGameOverScreen(std::string username,int score, Window* window)=0;
		virtual AudioEngine* getAudioEngine()=0;
		virtual Screen* createSettingsScreen(Window* window,std::string* username)=0;
		virtual Screen* createNextLevelScreen(int difficulty,Window* window)=0;
};
}
#endif

