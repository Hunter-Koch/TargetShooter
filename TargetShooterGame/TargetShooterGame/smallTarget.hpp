/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: A header file for smallTarget, this will be used as one
* of the many target variants used in the game. It will spawn randomly
* on the screen, be smaller than the base target, and disappear quicker than
* the base target.
*****************************************************************/

#ifndef SMALL
#define SMALL

#include "Target.hpp"

class smallTarget : public Target
{
public:

	/*
	* Function: smallTarget() : Target()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Default Constructor for smallTarget
	* Input parameters: void
	* Returns: N/A
	* Preconditions: Target object has to be created. 
	* Postconditions: Initalizes data members and loads proper files.
	*/
	smallTarget() : Target()
	{
		this->setTimeAlive(1);
		this->setScoreAwarded(2);
		this->setRadius(40);

		sf::SoundBuffer newAppearSound("Assets\\sounds\\SmallBeep.wav");
		this->setAppearEffect(newAppearSound);
		sf::SoundBuffer newDissapearSound("Assets\\sounds\\LittlePing.mp3");
		this->setDestroyEffect(newDissapearSound);
	}

	/*
	* Function: void smallTarget::destroy()
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
	* Function: void smallTarget::appear()
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