#ifndef FLOATING
#define FLOATING

#include "Target.hpp"

class floatingTarget :public Target
{
public:
	floatingTarget() : Target() {}

    // overloaded functions
    void destroy();
    void appear();

    void update() override;

private:
    
    float x = 0;
    float speed = 0.2f; // Adjust for how fast it moves
    float amplitude = 200.f; // Curve height
    float frequency = 0.007f; // Curve tightness
    float baseY = 300.f;
  

};

#endif