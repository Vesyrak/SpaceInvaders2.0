#ifndef TIMER_H
#define TIMER_H

namespace Game_Core {

	//Fundamental class for tracking time.
	class Timer {
		public:
			Timer();
			virtual ~Timer();
			void Start();
			void Stop();
			void Pause();
			void UnPause();
			virtual void Delay(int duration)=0;
			long GetTicks();
			bool IsRunning();
			bool IsPaused();
		protected:
			virtual long GetLocalTicks()=0;
			long startTicks;
			long pausedTicks;
			bool paused;
			bool started;
	};
}
#endif
