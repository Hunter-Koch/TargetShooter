#ifndef HEALTHY
#define HEALTHY

#include "Target.hpp"

class HealthyTarget : public Target
{
public:
	HealthyTarget() : Target()
	{
		this->health = 2;
	};
	HealthyTarget(int newHealth);

	void deincrementHealth();
	int getHealth();
	void setHealth(int newHealth);
	bool isDestroyed();

private:
	int health;
};

#endif