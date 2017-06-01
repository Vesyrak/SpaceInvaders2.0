#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

namespace Game_Core {

	//Enum of sound effects
	enum SoundType {
		Shoot, Damaged, Death
	};

	//Abstract class for audio playing
	class AudioEngine {
		public:
			virtual ~AudioEngine() {
			}
			virtual void PlaySound(SoundType sound)=0;
			virtual void PlayBackground()=0;
	};
}
#endif
