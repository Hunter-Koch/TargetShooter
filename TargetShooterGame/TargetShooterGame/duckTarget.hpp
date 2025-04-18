#ifndef DUCK
#define DUCK

#include "Target.hpp"

class duckTarget : public Target
{
public:
	duckTarget() : Target()
	{
		this->getTexture().loadFromFile("Assets\\targets\\Duck\\duck.png");
		this->setTexture(&getTexture(), true);
		this->setRadius(60);
		this->setTimeAlive(7);
		this->setScoreAwarded(3);
	}

	void appear() override;
	void destroy() override;
	 
	void update() override;

private:
	int direction = 1;
	float speed = 0.15f; // adjust if needed
};

#endif