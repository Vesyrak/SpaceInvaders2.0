#include "Timer.h"
namespace Game_Core {

Timer::Timer()
{
    //Initialize the variables
    startTicks = 0;
    pausedTicks = 0;

    paused = false;
    started = false;
}
Timer::~Timer(){

}
void Timer::Start()
{
    //Start the timer
    started = true;

    //Unpause the timer
    paused = false;

    //Get the current clock time
    startTicks = GetLocalTicks();
    pausedTicks = 0;
}
void Timer::Stop()
{
    //Stop the timer
    started = false;

    //Unpause the timer
    paused = false;

    //Clear tick variables
    startTicks = 0;
    pausedTicks = 0;
}
void Timer::Pause()
{
    //If the timer is running and isn't already paused
    if( started && !paused )
    {
        //Pause the timer
        paused = true;

        //Calculate the paused ticks
        pausedTicks = GetLocalTicks() - startTicks;
        startTicks = 0;
    }
}
void Timer::UnPause()
{
    //If the timer is running and paused
    if( started && paused )
    {
        //Unpause the timer
        paused = false;

        //Reset the starting ticks
        startTicks = GetLocalTicks() - pausedTicks;

        //Reset the paused ticks
        pausedTicks = 0;
    }
}
long Timer::GetTicks()
{
    //The actual timer time
	long time = 0;

    //If the timer is running
    if( started )
    {
        //If the timer is paused
        if( paused )
        {
            //Return the number of ticks when the timer was paused
            time = pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            time = GetLocalTicks() - startTicks;
        }
    }

    return time;
}
bool Timer::IsRunning()
{
    //Timer is running and paused or unpaused
    return started && !paused;
}

bool Timer::IsPaused()
{
    //Timer is running and paused
    return paused && started;
}
}
