#include "floatingTarget.hpp"

void floatingTarget::appear()
{
    this->restartTimer();

    baseY = randRange(100, 600);

    if (rand() % 2 == 0)
    {
        direction = 1;
        x = 0;
    }
    else
    {
        direction = -1;
        x = 1280;
    }

    float y = baseY + amplitude * std::sin(frequency * x);
    this->setPosition(sf::Vector2f(x, y));

    this->setIsDestryed(false);
    this->playAppearEffect();
}

void floatingTarget::update() // ? needs to be called somewhere when it appears
{
    if (!this->getIsDestroyed())
    {
        x += speed * direction; 
        float y = baseY + amplitude * std::sin(frequency * x);
        this->setPosition(sf::Vector2f(x, y));

        
        if ((direction == 1 && x > 1280) || (direction == -1 && x < 0))
        {
            this->destroy();
        }

        
        if (this->getTimeAlive() <= this->getTargetTimerInSeconds())
        {
            this->destroy();
        }
    }
}

void floatingTarget::destroy()
{
    this->stopTimer();
	this->setPosition(sf::Vector2f(0, 1000));
	this->playDestroyEffect();
	this->setIsDestryed(true);
}