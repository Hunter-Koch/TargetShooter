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

bool HealthyTarget::isDestroyed()
{
	return this->health <= 1;//could also be "<= 0" depending on whether 1 or 0 is the first value 
}
