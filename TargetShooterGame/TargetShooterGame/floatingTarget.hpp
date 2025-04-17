#ifndef FLOATING
#define FLOATING

#include "Target.hpp"

class floatingTarget :public Target
{
public:
	floatingTarget() : Target() {}

    // overloaded functions
    void destroy() override;
    void appear() override;

    void update() override;

private:
    float x = 0;
    float speed = 0.1f; // Adjust for how fast it moves
    float amplitude = 100.0f; // Curve height
    float frequency = 0.007f; // Curve tightness
    float baseY = 300.0f;
};

#endif