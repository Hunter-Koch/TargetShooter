/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: A header file for duckTarget, this will be used as one
* of the many target variants used in the game.
*****************************************************************/

#ifndef DUCK
#define DUCK

#include "Target.hpp"

class duckTarget : public Target
{
public:
	/*
	* Function:	duckTarget() : Target()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Default Constructor for duckTarget.
	* Input parameters: void
	* Returns: N/A
	* Preconditions: duckTarget object has to be created.
	* Postconditions: Initalizes data members and loads proper files.
	*/
	duckTarget() : Target()
	{
		this->getTexture().loadFromFile("Assets\\targets\\Duck\\duck.png");
		this->setTexture(&getTexture(), true);
		this->setRadius(60);
		this->setTimeAlive(7);
		this->setScoreAwarded(1);

		sf::SoundBuffer newAppearSound("Assets\\sounds\\Flapping.wav");
		this->setAppearEffect(newAppearSound);
		sf::SoundBuffer newDissapearSound("Assets\\sounds\\Quack.mp3");
		this->setDestroyEffect(newDissapearSound);
	}

	/*
	* Function: void duckTarget::appear()
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

	/*
	* Function: void duckTarget::destroy()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Overloaded destroy function from base target class, Groups operations that should occur when target appears.
	* Input parameters: void
	* Returns: void
	* Preconditions: Data member isDestroyed must be false.
	* Postconditions: Applies operations that should occur when target is destroyed, including stopping targetTimer,
	*					setting position, playing destroy effect, and setting isDestroyed to true.
	*/
	void destroy() override;

	/*
	* Function: void duckTarget::update()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Overloaded function for use in gameDirector.hpp. Groups operations that should occur each tick when target is not
					destroyed including movement.
	* Input parameters: void
	* Returns: void
	* Preconditions: Data member isDestroyed must be false.
	* Postconditions: Applies operations that should occur when target is not destoyed, such as moving.
	*/
	void update() override;

private:
	int direction = 1;
	float speed = 0.15f; // adjust if needed
};

#endif