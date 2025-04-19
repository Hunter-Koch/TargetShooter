#ifndef HEALTHY
#define HEALTHY

#include "Target.hpp"

class HealthyTarget : public Target
{
public:
	HealthyTarget() : Target()
	{
		this->getTexture().loadFromFile("Assets\\targets\\HealthyTarget.png");
		this->setTexture(&getTexture(), true);
		this->health = 2;
	};
	HealthyTarget(int newHealth);

	void deincrementHealth();
	int getHealth();
	void setHealth(int newHealth);

	//overloaded functions
	void destroy() override;
	void appear() override;

	
private:
	int health;
};

#endif