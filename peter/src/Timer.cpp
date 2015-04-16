#include <Timer.hpp>

namespace ct
{

Timer::Timer() 
    : startTime(Timer::hr::time_point::min())
    , endTime(Timer::hr::time_point::max())
    , running(false)
{ }

void Timer::toggle()
{
    if (!running) start(); else stop();

    running = !running;
}

void Timer::start() { startTime = hr::now(); }
void Timer::stop() { endTime = hr::now(); }

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