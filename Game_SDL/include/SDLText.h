#ifndef SDLTEXT_H
#define SDLTEXT_H
#include "SDLContext.h"
#include "Text.h"
using namespace Game_Core;

namespace Game_SDL {

	//SDL implementation of Text
	class SDLText: public Text {
		public:
			SDLText(SDLContext* context, std::string message, int x, int y, int size);
			SDLText(SDLContext* context, std::string message, int x, int y);
			~SDLText();
			void Visualise();
			void Update(std::string message);
			void CenterText(BoundingBox* outerBounds);
			void HorizontalCenterText(int x, int width);
			void VerticalCenterText(int y, int height);
		private:
			SDLContext* context;
			SDL_Texture* texture;
	};
}
#endif
