#include "duckTarget.hpp"

void duckTarget::appear()
{
	this->restartTimer();
	this->setPosition(sf::Vector2f(0, randRange(0, 550)));
	this->playAppearEffect();
	this->setIsDestryed(false);
	direction = 1;
}

void duckTarget::update()
{
	if (!this->getIsDestroyed())
	{
		sf::Vector2f position = this->getPosition();
		position.x += speed * direction;

		auto bounds = this->getGlobalBounds();
		float width = bounds.size.x;

		if (position.x <= 0)
		{
			position.x = 0;
			direction = 1;
			this->setScale(sf::Vector2f(1, 1));
		}
		else if (position.x + width >= 1280)
		{
			position.x = 1280 - width;
			direction = -1;
			this->setScale(sf::Vector2f(-1, 1));
		}

		this->setPosition(position);

		if (this->getTimeAlive() <= this->getTargetTimerInSeconds())
		{
			this->destroy();
		}
	}
}

void duckTarget::destroy()
{
	this->stopTimer();
	this->setPosition(sf::Vector2f(0, 1000));
	this->playDestroyEffect();
	this->setIsDestryed(true);
}