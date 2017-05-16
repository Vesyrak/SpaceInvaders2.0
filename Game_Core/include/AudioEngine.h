#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H
namespace Game_Core {
	enum SoundType {
		Shoot, Damaged, Death
	};
	class AudioEngine {
		public:
			virtual ~AudioEngine() {
			}
			virtual void PlaySound(SoundType sound)=0;
			virtual void PlayBackground()=0;
	};
}
#endif
