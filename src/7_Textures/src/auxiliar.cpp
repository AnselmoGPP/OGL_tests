#include "auxiliar.hpp"

// ----- stdTime ---------------

stdTime::stdTime() : 
    startingTime(std::chrono::high_resolution_clock::now()) { }

long double stdTime::GetTime()
{
    currentTime = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(currentTime - startingTime).count() / 1000000.l;
}

// ----- fpsCheck ---------------

fpsCheck::fpsCheck() :
    previousTime(std::chrono::high_resolution_clock::now()),
    currentTime(std::chrono::system_clock::duration::zero()) { }

int fpsCheck::GetFPS()
{
    currentTime = std::chrono::high_resolution_clock::now();

    int fps = 1000000 / std::chrono::duration_cast<std::chrono::microseconds>(currentTime - previousTime).count();

    previousTime = currentTime;
    return fps;
}

// ----- ---------------
