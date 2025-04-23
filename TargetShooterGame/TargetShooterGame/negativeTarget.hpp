/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: A header file for negativeTarget, this will be used as one
* of the many target variants used in the game. It will spawn randomly
* on the screen and will remove a player's score if they shoot them.
*****************************************************************/

#ifndef NEGATIVE
#define NEGATIVE

#include "Target.hpp"

class negativeTarget : public Target
{
public:

	/*
	* Function: negativeTarget() : Target()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Default Constructor for negativeTarget
	* Input parameters: void
	* Returns: N/A
	* Preconditions: Target object has to be created.
	* Postconditions: Initalizes data members and loads proper files.
	*/
	negativeTarget() : Target()
	{
		this->getTexture().loadFromFile("Assets\\targets\\NegativeTarget.png");
		this->setTexture(&getTexture(), true);
		this->setTimeAlive(4);
		this->setScoreAwarded(-5);
		sf::SoundBuffer newAppearSound("Assets\\sounds\\NegativeTargetAppear.mp3");
		sf::SoundBuffer newDissapearSound("Assets\\sounds\\NegativeTargetDestroy.wav");
		this->setAppearEffect(newAppearSound);
		this->setDestroyEffect(newDissapearSound);
	}

	/*
	* Function: void negativeTarget::destroy()
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
	* Function: void negativeTarget::appear()
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

};

#endif