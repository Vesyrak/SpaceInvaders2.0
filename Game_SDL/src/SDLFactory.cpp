#include "SDLFactory.h"
using namespace std;
namespace Game_SDL {

	SDLFactory::SDLFactory() {
		audioEngine = NULL;
		context = NULL;
		inputHandler = NULL;
	}
	SDLFactory::~SDLFactory() {
		delete context;
		delete audioEngine;
		delete inputHandler;
	}

	Basher* SDLFactory::CreateBasher(std::vector<Entity*>* bulletVector, int x, int y, int movementSpeed) {
		return new SDLBasher(context, this, bulletVector, x, y, movementSpeed);
	}

	Blaster* SDLFactory::CreateBlaster(std::vector<Entity*>* bulletVector, int x, int y, int movementSpeed) {
		return new SDLBlaster(context, this, bulletVector, x, y, movementSpeed);
	}

	Bomber* SDLFactory::CreateBomber(std::vector<Entity*>* bulletVector, int x, int y, int movementSpeed) {
		return new SDLBomber(context, this, bulletVector, x, y, movementSpeed);
	}

	PlayerShip* SDLFactory::CreatePlayerShip(std::vector<Entity*>* bulletVector, int lives, int x, int y, int movementSpeed) {
		return new SDLPlayerShip(context, this, bulletVector, lives, x, y, movementSpeed);
	}

	Laser* SDLFactory::CreateLaser(int x, int y, int movementSpeed, InputType direction, int damage) {
		return new SDLLaser(context, x, y, movementSpeed, direction, damage);
	}

	LaserBomb* SDLFactory::CreateLaserBomb(int x, int y, int movementSpeed, InputType direction, int damage) {
		return new SDLLaserBomb(context, x, y, movementSpeed, direction, damage);
	}

	AudioEngine* SDLFactory::GetAudioEngine() {
		if (audioEngine == NULL) {
			audioEngine = new SDLAudioEngine();
		}
		return audioEngine;
	}

	Input* SDLFactory::GetInputHandler() {
		if (inputHandler == NULL) {
			inputHandler = new SDLInput();
		}
		return inputHandler;
	}

	Timer* SDLFactory::CreateTimer() {
		return new SDLTimer();
	}

	Background* SDLFactory::CreateBackground() {
		return new SDLBackground(context);
	}

	Healthbar* SDLFactory::CreateHealthbar(Entity* observed, int x, int y) {
		return new SDLHealthbar(context, this, observed, x, y);
	}

	Text* SDLFactory::CreateText(std::string message, int x, int y) {
		return new SDLText(context, message, x, y);
	}
	Text* SDLFactory::CreateText(std::string message, int x, int y, int size) {
		return new SDLText(context, message, x, y, size);
	}

	Screen* SDLFactory::CreateMenu(Window* window) {
		return new SDLMenu(context, this, window);
	}

	Screen* SDLFactory::CreateSettingsScreen(Window* window, std::string* username) {
		return new SDLSettingsScreen(context, this, window, username);
	}

	Screen* SDLFactory::CreateNextLevelScreen(int difficulty, Window* window) {
		return new SDLNextLevelScreen(this,difficulty, window);
	}

	Screen* SDLFactory::CreateGameOverScreen(std::string username, int score, Window* window) {
		return new SDLGameOverScreen(context, this, username, score, window);
	}

	Window* SDLFactory::CreateWindow(int screen_width, int screen_height) {
		SDLWindow* window = new SDLWindow(screen_width, screen_height);
		this->context = new SDLContext(window);
		return window;
	}
}
