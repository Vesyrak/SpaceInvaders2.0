#ifndef TIMER_H
#define TIMER_H
class Timer{
public:
	Timer();
	virtual ~Timer();
	void start();
	void stop();
	void pause();
	void unpause();
	virtual void delay(int duration)=0;

    //Gets the timer's time
    long getTicks();

    //Checks the status of the timer
    bool isRunning();
    bool isPaused();

protected:
    long mStartTicks;

    //The ticks stored when the timer was paused
    long mPausedTicks;

    //The timer status
    bool mPaused;
    bool mStarted;
    virtual long getLocalTicks()=0;
};
#endif
