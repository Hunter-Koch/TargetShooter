#ifndef FAST
#define FAST

#include "Target.hpp"



class fastTarget : public Target
{
public:
	fastTarget(): Target()
	{
		this->setTimeAlive(7);
		this->setScoreAwarded(3);

		fastRight.loadFromFile("Assets\\targets\\FastTargetRight.png");
		fastLeft.loadFromFile("Assets\\targets\\FastTargetLeft.png");
		fastUp.loadFromFile("Assets\\targets\\FastTargetUp.png");
		fastDown.loadFromFile("Assets\\targets\\FastTargetDown.png");

		speed = 0.7f;
	}

	sf::Texture fastRight;
	sf::Texture fastLeft;
	sf::Texture fastUp;
	sf::Texture fastDown;

	void appear() override;
	void destroy() override;

	void update() override;

	sf::Clock preAppear;

private:
	int direction = 1;
//	int directionY = 1;
	float speed;
//	float verticalSpeed = 0.5f;

	bool waiting = false;
	bool soundPlayed = false;
};

#endif