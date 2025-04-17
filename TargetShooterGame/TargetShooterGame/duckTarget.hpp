#ifndef DUCK
#define DUCK

#include "Target.hpp"

class duckTarget : public Target
{
public:
	duckTarget() : Target() {}

	void appear();
	void destroy();

	void update() override;

private:
	int direction = 1;
	float speed = 2.0f; // adjust if needed
	float y = 620.0f; // ?
};

#endif