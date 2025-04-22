/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: A header file for HealthyTarget, this will be used as one
* of the many target variants used in the game. It will spawn randomly
* on the screen and require the player to shoot it multiple times to 
* destroy it.
*****************************************************************/

#ifndef HEALTHY
#define HEALTHY

#include "Target.hpp"

class HealthyTarget : public Target
{
public:

	/*
	* Function: HealthyTarget() : Target(), hitSound(hitEffect)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Default Constructor for HealthyTarget.
	* Input parameters: void
	* Returns: N/A
	* Preconditions: Target object has to be created.
	* Postconditions: Initalizes data members and loads proper files.
	*/
	HealthyTarget() : Target(), hitSound(hitEffect)
	{
		this->getTexture().loadFromFile("Assets\\targets\\HealthyTarget.png");
		this->setTexture(&getTexture(), true);
		this->setHealth(2);
		this->hitEffect.loadFromFile("Assets\\sounds\\Ping.wav");
		this->hitSound.setVolume(50);//ranges from 0-100
		this->setScoreAwarded(1);

		sf::SoundBuffer newAppearSound;
		newAppearSound.loadFromFile("Assets\\sounds\\MetalClick.wav");

		this->setAppearEffect(newAppearSound);

		sf::SoundBuffer newDissapearSound;
		newDissapearSound.loadFromFile("Assets\\sounds\\Clang.mp3");

		this->setDestroyEffect(newDissapearSound);
	};

	/*
	* Function: HealthyTarget(int newHealth) : hitSound(hitEffect)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Parameter Constructor for HealthyTarget.
	* Input parameters: void
	* Returns: N/A
	* Preconditions: Target object has to be created.
	* Postconditions: Initalizes data members and loads proper files.
	*/
	HealthyTarget(int newHealth) : hitSound(hitEffect)
	{
		this->health = (newHealth - 1);
		this->hitEffect.loadFromFile("Assets\\sounds\\Ping.wav");
		this->hitSound.setVolume(50);//ranges from 0-100
		this->setScoreAwarded(1);

		sf::SoundBuffer newAppearSound;
		newAppearSound.loadFromFile("Assets\\sounds\\MetalClick.wav");

		//sf::SoundBuffer newAppearSound("Assets\\sounds\\MetalClick.wav");
		this->setAppearEffect(newAppearSound);

		sf::SoundBuffer newDissapearSound;
		newDissapearSound.loadFromFile("Assets\\sounds\\Clang.mp3");

		/*sf::SoundBuffer newDissapearSound("Assets\\sounds\\Clang.mp3");*/
		this->setDestroyEffect(newDissapearSound);
	};

	/*
	* Function: void HealthyTarget::deincrementHealth()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Deincrements health data member by 1.
	* Input parameters: void
	* Returns: void
	* Preconditions: Hit effect must be loaded, health is greater than 0.
	* Postconditions: Deincrements health data member by 1.
	*/
	void deincrementHealth();

	/*
	* Function: int HealthyTarget::getHealth()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: HealthyTarget getter for health data member.
	* Input parameters: void
	* Returns: int
	* Preconditions: N/A
	* Postconditions: Returns value of health data member.
	*/
	int getHealth();

	/*
	* Function: void HealthyTarget::setHealth(int newHealth)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: HealthyTarget setter for health data member.
	* Input parameters: int newHealth
	* Returns: void
	* Preconditions: int newHealth > -1.
	* Postconditions: Modifies health data member to value of int newHealth.
	*/
	void setHealth(int newHealth);
	
	/*
	* Function: void HealthyTarget::playHitEffect()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Plays destroy effect data member.
	* Input parameters: void
	* Returns: void
	* Preconditions: destroyEffect must be loaded.
	* Postconditions: Plays destroyEffect in application. 
	*/
	void playHitEffect();

	/*
	* Function: void HealthyTarget::destroy()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Overloaded destroy function from base target class, Groups operations that should occur when target appears.
	* Input parameters: void
	* Returns: void
	* Preconditions: Data member isDestroyed must be false.
	* Postconditions: Applies operations that should occur when target is destroyed, including stopping targetTimer,
	*					setting position, playing destroy effect, and setting isDestroyed to true or deincrementing health.
	*/
	void destroy() override;

	/*
	* Function: void HealthyTarget::appear()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Overloaded appear function from base target class, Groups operations that should occur when target appears.
	* Input parameters: void
	* Returns: void
	* Preconditions: Data member isDestroyed must be true.
	* Postconditions:Applies operations that should occur when target appears, including restarting targetTimer,
	*					setting position, playing appear effect, and setting isDestroyed to false.
	*/
	void appear() override;

	
private:
	int health;
	sf::SoundBuffer hitEffect;
	sf::Sound hitSound;
};

#endif