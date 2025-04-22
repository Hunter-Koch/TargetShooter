/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: A header file for fastTarget, this will be used as one
* of the many target variants used in the game. It will spawn at 
* the sides and quickly shoot accross the screen.
*****************************************************************/

#ifndef FAST
#define FAST

#include "Target.hpp"



class fastTarget : public Target
{
public:
	/*
	* Function: fastTarget(): Target()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Default Constructor for fastTarget
	* Input parameters: void
	* Returns: N/A
	* Preconditions: Target object has to be created.
	* Postconditions: Initalizes data members and loads proper files.
	*/
	fastTarget(): Target()
	{
		this->setTimeAlive(7);
		this->setScoreAwarded(3);

		fastRight.loadFromFile("Assets\\targets\\FastTargetRight.png");
		fastLeft.loadFromFile("Assets\\targets\\FastTargetLeft.png");
		fastUp.loadFromFile("Assets\\targets\\FastTargetUp.png");
		fastDown.loadFromFile("Assets\\targets\\FastTargetDown.png");

		sf::SoundBuffer newAppearSound("Assets\\sounds\\whoosh.wav");
		this->setAppearEffect(newAppearSound);
		sf::SoundBuffer newDissapearSound("Assets\\sounds\\thud.wav");
		this->setDestroyEffect(newDissapearSound);
		speed = 0.7f;
	}

	/*
	* Function: void fastTarget::appear()
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
	* Function: void fastTarget::destroy()
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
	* Function: void fastTarget::update()
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

	sf::Clock preAppear;
	sf::Texture fastRight;
	sf::Texture fastLeft;
	sf::Texture fastUp;
	sf::Texture fastDown;

private:
	int direction = 1;
	float speed;

	bool waiting = false;
	bool soundPlayed = false;
};

#endif