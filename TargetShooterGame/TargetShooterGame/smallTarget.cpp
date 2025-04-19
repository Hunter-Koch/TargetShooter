#include "smallTarget.hpp"

void smallTarget::appear()
{
	this->restartTimer();
	this->setPosition(sf::Vector2f(randRange(0, 1000), randRange(0, 500)));
	this->playAppearEffect();
	
	this->setIsDestryed(false);
}

void smallTarget::destroy()
{
	this->stopTimer();
	this->setPosition(sf::Vector2f(0, 1000));
	this->playDestroyEffect();
	this->setIsDestryed(true);
}