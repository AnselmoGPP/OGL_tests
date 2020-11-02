#ifndef AUXILIAR_HPP
#define AUXILIAR_HPP

#include "Eigen/Dense"

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

namespace EigenCG
{
// Model matrix
Eigen::Matrix4f translate(Eigen::Matrix4f matrix, Eigen::Vector3f position);
Eigen::Matrix4f rotate(Eigen::Matrix4f matrix, float radians, Eigen::Vector3f axis);
Eigen::Matrix4f scale(Eigen::Matrix4f matrix, Eigen::Vector3f factor);

// View matrix
Eigen::Matrix4f lookAt(Eigen::Vector3f camPosition, Eigen::Vector3f target, Eigen::Vector3f upVector);

// Projection matrix
Eigen::Matrix4f ortho(float left, float right, float bottom, float top, float nearP);
Eigen::Matrix4f perspective(float radians, float ratio, float nearPlane, float farPlane);

// Auxiliar
float radians(float sexagesimalDegrees);
float * value_ptr(Eigen::Matrix4f matrix);

} // EigenCG end




#endif
