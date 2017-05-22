#include "SDLHealthbar.h"
namespace Game_SDL {

	SDLHealthbar::SDLHealthbar(SDLContext* context, AbstractFactory* factory, Entity* observed, int x, int y) :Healthbar(factory, observed, x, y) {
		this->context = context;
		this->prevhp = this->starthp = observed->GetHP();
		backColor= {255,255,255,255};
		frontColor= {0,128,0,255};
	}
	SDLHealthbar::~SDLHealthbar() {
	}

	//Updates the healthbar
	void SDLHealthbar::Update() {
		//If the object it observes' hp has changed, update
		if (observed->GetHP() != prevhp) {
			prevhp = observed->GetHP();
			if (observed->GetHP() / (double) starthp * 100 > 65)
				frontColor= {0,128,0,255};
				else if(observed->GetHP()/(double) starthp*100>30)
				frontColor= {128,128,0,255};
				else frontColor= {128,0,0,255};
			foreBounds->SetWidth(observed->GetHP() / (double) starthp * (backBounds->GetWidth() - 2));
		}
	}
	void SDLHealthbar::Visualise() {
		hpText->Visualise();
		context->DrawRect(&backColor, backBounds, false);
		context->DrawRect(&frontColor, foreBounds, true);
	}
}
