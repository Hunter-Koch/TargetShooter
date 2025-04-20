#ifndef FLOATING
#define FLOATING

#include "Target.hpp"

class floatingTarget :public Target
{
public:
	floatingTarget() : Target()
    {
        this->getTexture().loadFromFile("Assets\\targets\\BalloonTarget.png");
        this->setTexture(&getTexture(), true);
        this->setScoreAwarded(1);
        this->setTimeAlive(7);
        sf::SoundBuffer newAppearSound("Assets\\sounds\\BalloonInflate.wav");
        this->setAppearEffect(newAppearSound);
        sf::SoundBuffer newDissapearSound("Assets\\sounds\\BalloonPop.wav");
        this->setDestroyEffect(newDissapearSound);
    }

    
    
    // overloaded functions
    void destroy() override;
    void appear() override;

    void update() override;

private:
    int direction = 1;
    float x = 0;
    float speed = 0.1f; // Adjust for how fast it moves
    float amplitude = 100.0f; // Curve height
    float frequency = 0.007f; // Curve tightness
    float baseY = 300.0f;
};

#endif