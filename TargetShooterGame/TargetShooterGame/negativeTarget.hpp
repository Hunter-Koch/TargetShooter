#ifndef NEGATIVE
#define NEGATIVE

#include "Target.hpp"

class negativeTarget : public Target
{
public:
	negativeTarget() : Target()
	{
		this->getTexture().loadFromFile("Assets\\targets\\NegativeTarget.png");
		this->setTexture(&getTexture(), true);
		this->setTimeAlive(4);
		this->setScoreAwarded(-5);

	}

	void destroy() override;
	void appear() override;

private:

};

#endif