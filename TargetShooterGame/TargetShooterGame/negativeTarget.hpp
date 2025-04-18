#ifndef NEGATIVE
#define NEGATIVE

#include "Target.hpp"

class negativeTarget : public Target
{
public:
	negativeTarget() : Target()
	{
		this->getTexture().loadFromFile("Assets\\targets\\basic\\inverted.png");
		this->setTexture(&getTexture(), true);
		this->setTimeAlive(7);
		this->setScoreAwarded(-3);

	}

	void destroy() override;
	void appear() override;

private:

};

#endif