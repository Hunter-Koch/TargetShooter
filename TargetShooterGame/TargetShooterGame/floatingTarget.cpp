#include "floatingTarget.hpp"

void floatingTarget::appear()
{
    x = 0;
    baseY = randRange(50, 500); // Spawn height varies ?
    this->setPosition(sf::Vector2f(x, baseY));
    this->setIsDestryed(false);
    this->playAppearEffect();
}

void floatingTarget::update() // ? needs to be called somewhere when it appears
{
    if (!this->getIsDestroyed())
    {
        x += speed;
        float y = baseY + amplitude * std::sin(frequency * x);
        this->setPosition(sf::Vector2f(x, y));

        // Check if it's off screen
        if (this->getPosition().x > 1280) 
        {
            this->destroy(); 
        }
    }
}

void floatingTarget::destroy()
{
	this->setPosition(sf::Vector2f(0, 1000));
	this->playDestroyEffect();
	this->setIsDestryed(true);
}