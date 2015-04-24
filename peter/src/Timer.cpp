#include <Timer.hpp>

namespace ct
{

Timer::Timer(ct::Times * const times) 
    : startTime(Timer::hr::time_point::min())
    , endTime(Timer::hr::time_point::max())
    , running(false)
    , times(times)
{ }

void Timer::toggle()
{
    if (!running) start(); else stop();
}

void Timer::start() 
{ 
    startTime = hr::now(); 
    running = true;
}
void Timer::stop() 
{ 
    endTime = hr::now(); 
    running = false;

    times->log(elapsed());
}

float Timer::elapsed()
{
    hr::time_point end;
    hr::time_point now = hr::now();
    if (running)
        end = now;  //heh, fortunately not so
    else
        end = endTime;

    return std::chrono::duration_cast<ms>(end - startTime).count() / 1000.f;
}

}