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

		sf::SoundBuffer newAppearSound("Assets\\sounds\\SmallBeep.wav");
		this->setAppearEffect(newAppearSound);
		sf::SoundBuffer newDissapearSound("Assets\\sounds\\LittlePing.mp3");
		this->setDestroyEffect(newDissapearSound);
	}

	void destroy() override;
	void appear() override;



private:

};

#endif