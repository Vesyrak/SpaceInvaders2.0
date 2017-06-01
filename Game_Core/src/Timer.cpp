#include "Timer.h"

namespace Game_Core {

	//Constructor sets required parameters
	Timer::Timer() {
		startTicks = 0;
		pausedTicks = 0;
		paused = false;
		started = false;
	}

	Timer::~Timer() {

	}

	//Starts the timer and sets the corresponding variables
	void Timer::Start() {
		started = true;
		paused = false;
		startTicks = GetLocalTicks();
		pausedTicks = 0;
	}

	//Stops the timer
	void Timer::Stop() {
		started = false;
		paused = false;
		startTicks = 0;
		pausedTicks = 0;
	}

	//Pauses the timer
	void Timer::Pause() {
		if (started && !paused) {
			paused = true;
			pausedTicks = GetLocalTicks() - startTicks;
			startTicks = 0;
		}
	}

	//And unpauses
	void Timer::UnPause() {
		if (started && paused) {
			paused = false;
			startTicks = GetLocalTicks() - pausedTicks;
			pausedTicks = 0;
		}
	}

	//Get the ticks passed
	long Timer::GetTicks() {
		long time = 0;
		if (started) {
			if (paused) {
				time = pausedTicks;
			}
			else {
				time = GetLocalTicks() - startTicks;
			}
		}
		return time;
	}

	bool Timer::IsRunning() {
		return started && !paused;
	}

	bool Timer::IsPaused() {
		return paused && started;
	}
}
