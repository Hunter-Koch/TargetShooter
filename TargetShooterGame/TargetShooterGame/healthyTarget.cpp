#include "healthyTarget.hpp"

HealthyTarget::HealthyTarget(int newHealth)
{
	this->health = (newHealth - 1);
}

void HealthyTarget::deincrementHealth()
{
	this->health--;
}

int HealthyTarget::getHealth()
{
	return this->health;
}

void HealthyTarget::setHealth(int newHealth)
{
	this->health = newHealth;
}

void HealthyTarget::destroy()
{
	if (this->health >= 1)
	{
		this->health--;
	}
	else
	{
		this->setPosition(sf::Vector2f(0, 1000));
		this->playDestroyEffect();
		this->setIsDestryed(true);
	}
}

void HealthyTarget::appear()
{
	this->setPosition(sf::Vector2f(randRange(0, 1000), randRange(0, 500)));
	this->playAppearEffect();
	this->setIsDestryed(false);
}
