#ifndef SMALL
#define SMALL

#include "Target.hpp"

class smallTarget : public Target
{
public:
	smallTarget() : Target()
	{
		this->setTimeAlive(1);
		this->setScoreAwarded(3);
		this->setRadius(40);
	}

	void destroy() override;
	void appear() override;



private:

};

#endif