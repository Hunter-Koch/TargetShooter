/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: Content file that will include the definitons for
* the healthyTarget.hpp file.
*****************************************************************/

#include "healthyTarget.hpp"

void HealthyTarget::deincrementHealth()
{
	playHitEffect();
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

void HealthyTarget::playHitEffect()
{
	hitSound.setBuffer(this->hitEffect);
	hitSound.play();
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
	this->setHealth(2);
	this->setPosition(sf::Vector2f(randRange(0, 1000), randRange(0, 500)));
	this->playAppearEffect();
	this->setIsDestryed(false);
}
