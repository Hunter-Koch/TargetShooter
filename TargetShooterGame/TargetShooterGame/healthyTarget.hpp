#ifndef HEALTHY
#define HEALTHY

#include "Target.hpp"

class HealthyTarget : public Target
{
public:
	HealthyTarget() : Target(), hitSound(hitEffect)
	{
		this->getTexture().loadFromFile("Assets\\targets\\HealthyTarget.png");
		this->setTexture(&getTexture(), true);
		this->setHealth(2);
		this->hitEffect.loadFromFile("Assets\\sounds\\Ping.wav");
		this->hitSound.setVolume(50);//ranges from 0-100
		this->setScoreAwarded(2);

		sf::SoundBuffer newAppearSound;
		newAppearSound.loadFromFile("Assets\\sounds\\MetalClick.wav");

		//sf::SoundBuffer newAppearSound("Assets\\sounds\\MetalClick.wav");
		this->setAppearEffect(newAppearSound);

		sf::SoundBuffer newDissapearSound;
		newDissapearSound.loadFromFile("Assets\\sounds\\Clang.mp3");

		/*sf::SoundBuffer newDissapearSound("Assets\\sounds\\Clang.mp3");*/
		this->setDestroyEffect(newDissapearSound);
	};
	HealthyTarget(int newHealth) : hitSound(hitEffect)
	{
		this->health = (newHealth - 1);
		this->hitEffect.loadFromFile("Assets\\sounds\\Ping.wav");
		this->hitSound.setVolume(50);//ranges from 0-100
		this->setScoreAwarded(2);

		sf::SoundBuffer newAppearSound;
		newAppearSound.loadFromFile("Assets\\sounds\\MetalClick.wav");

		//sf::SoundBuffer newAppearSound("Assets\\sounds\\MetalClick.wav");
		this->setAppearEffect(newAppearSound);

		sf::SoundBuffer newDissapearSound;
		newDissapearSound.loadFromFile("Assets\\sounds\\Clang.mp3");

		/*sf::SoundBuffer newDissapearSound("Assets\\sounds\\Clang.mp3");*/
		this->setDestroyEffect(newDissapearSound);
	};

	void deincrementHealth();
	int getHealth();
	void setHealth(int newHealth);
	
	void playHitEffect();
	//overloaded functions
	void destroy() override;
	void appear() override;

	
private:
	int health;
	sf::SoundBuffer hitEffect;
	sf::Sound hitSound;
};

#endif