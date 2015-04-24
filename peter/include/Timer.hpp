#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <Times.hpp>

namespace ct
{

class Timer
{
public:
    Timer(ct::Times * const times);

    void toggle();

    typedef std::chrono::milliseconds ms;
    float elapsed();
private:
    typedef std::chrono::high_resolution_clock hr;
    hr::time_point startTime;
    hr::time_point endTime;

    void start();
    void stop();
    bool running;

    ct::Times * const times;
};

}



#endif