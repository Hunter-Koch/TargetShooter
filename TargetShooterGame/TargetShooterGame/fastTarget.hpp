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
	}

	void appear() override;
	void destroy() override;

	void update() override;

	sf::Clock preAppear;

private:
	int direction = 1;
	float speed = 1.0f;

	bool waiting = false;
	bool soundPlayed = false;
};

#endif