#ifndef TIMER_H
#define TIMER_H
namespace Game_Core {

class Timer{
public:
	Timer();
	virtual ~Timer();
	void Start();
	void Stop();
	void Pause();
	void UnPause();
	virtual void Delay(int duration)=0;
    long GetTicks();

    //Checks the status of the timer
    bool IsRunning();
    bool IsPaused();

protected:
    virtual long GetLocalTicks()=0;

    long startTicks;

    //The ticks stored when the timer was paused
    long pausedTicks;
    //The timer status
    bool paused;
    bool started;
};}
#endif
