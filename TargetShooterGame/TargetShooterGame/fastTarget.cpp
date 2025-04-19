#include "fastTarget.hpp"

void fastTarget::appear()
{

	//this->restartTimer();
	//this->setIsDestryed(false);

	//// Set direction randomly
	//direction = (rand() % 2 == 0) ? 1 : -1;

	//// Spawn position based on direction
	//sf::Vector2f spawnPos = (direction == 1)
	//	? sf::Vector2f(0, randRange(100, 600))
	//	: sf::Vector2f(1280, randRange(100, 600));

	//waiting = true;
	//soundPlayed = false;
	//preAppear.restart();

	
	this->restartTimer();
	
	// spawn from left side or right side
	if (rand() % 2 == 0)
	{
		direction = 1; 
		this->setPosition(sf::Vector2f(0, randRange(100, 600)));
	}
	else
	{
		direction = -1; 
		this->setPosition(sf::Vector2f(1280, randRange(100, 600)));
	}
	this->playAppearEffect(); // change later so different effect plays before it appears to warn
	this->setIsDestryed(false);
}

void fastTarget::destroy()
{
	this->stopTimer();
	this->setPosition(sf::Vector2f(0, 1000));
	this->playDestroyEffect();
	this->setIsDestryed(true);
}

void fastTarget::update()
{

	if (!this->getIsDestroyed())
	{
		sf::Vector2f pos = this->getPosition();
		pos.x += speed * direction;
		this->setPosition(pos);

		if ((direction == 1 && pos.x > 1280) || (direction == -1 && pos.x < 0))
		{
			this->destroy();
		}

		if (this->getTimeAlive() <= this->getTargetTimerInSeconds())
		{
			this->destroy();
		}
	}
}