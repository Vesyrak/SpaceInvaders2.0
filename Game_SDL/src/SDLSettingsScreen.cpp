#include "SDLSettingsScreen.h"
namespace Game_SDL{
SDLSettingsScreen::SDLSettingsScreen(AbstractFactory* factory, SDLContext* context,Window* window):Screen(factory, window){
	username="Fernando";
	background=factory->createBackground();
	textBox=new SDLTextBox(factory,context, 120, 30);
}
SDLSettingsScreen::~SDLSettingsScreen(){
	delete textBox;
}

void SDLSettingsScreen::Update(){
	textBox->Update();
}
void SDLSettingsScreen::Visualise(){
	window->PrepareRender();
	background->Visualise();
	textBox->Visualise();
	window->PresentRender();
}
}
