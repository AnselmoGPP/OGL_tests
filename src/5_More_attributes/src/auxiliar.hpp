#ifndef AUXILIAR_HPP
#define AUXILIAR_HPP

#include <chrono>

class stdTime
{
    std::chrono::high_resolution_clock::time_point startingTime;
    std::chrono::high_resolution_clock::time_point currentTime;

public:
    stdTime();

    long double GetTime();       // Returns time in seconds since object creation
};

class fpsCheck
{
    std::chrono::high_resolution_clock::time_point previousTime;
    std::chrono::high_resolution_clock::time_point currentTime;

public:
    fpsCheck();

    int GetFPS();       // Get fps: function of time difference between 2 frames
};

#endif
