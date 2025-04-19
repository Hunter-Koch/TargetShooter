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

	direction = rand() % 4;

	sf::Vector2f pos;

	switch (direction)
	{
	case 0: // Right
		pos = sf::Vector2f(0, randRange(100, 600));
		this->setTexture(&fastRight, true);
		break;
	case 1: // Left
		pos = sf::Vector2f(1280, randRange(100, 600));
		this->setTexture(&fastLeft, true);
		break;
	case 2: // Down
		pos = sf::Vector2f(randRange(100, 1180), 0);
		this->setTexture(&fastDown, true);
		break;
	case 3: // Up
		pos = sf::Vector2f(randRange(100, 1180), 720);
		this->setTexture(&fastUp, true);
		break;
	}

	this->setPosition(pos);
	this->playAppearEffect();
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

		switch (direction)
		{
		case 0: pos.x += speed; break; // right
		case 1: pos.x -= speed; break; // left
		case 2: pos.y += speed; break; // down
		case 3: pos.y -= speed; break; // up
		}

		this->setPosition(pos);

		// Off-screen destruction
		if (pos.x < 0 || pos.x > 1280 || pos.y < 0 || pos.y > 720)
		{
			this->destroy();
		}


	}
}
