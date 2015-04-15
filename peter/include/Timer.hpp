#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

namespace ct
{

class Timer
{
public:
    Timer();

    void toggle();

    typedef std::chrono::milliseconds ms;
    ms elapsed();
private:
    typedef std::chrono::high_resolution_clock hr;
    hr::time_point startTime;
    hr::time_point endTime;

    void start();
    void stop();
    bool running;
};

}



#endif