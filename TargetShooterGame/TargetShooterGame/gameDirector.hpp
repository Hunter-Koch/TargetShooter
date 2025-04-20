/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 20, 2025
* Description: A header file for gameDirector, this will be used the main
* class to control and operate on the state of the game.
*****************************************************************/

#ifndef DIRECT
#define DIRECT

#include "healthyTarget.hpp"
#include "Timer.hpp"
#include "duckTarget.hpp"
#include "floatingTarget.hpp"
#include "negativeTarget.hpp"
#include "fastTarget.hpp"
#include "smallTarget.hpp"
#include "Player.hpp"

class GameDirector
{
public:

	/*
	* Function: GameDirector::GameDirector()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Default constructor for GameDirector.
	* Input parameters: void
	* Returns: N/A
	* Preconditions: GameDirector object has to be created.
	* Postconditions: Initalizes data members.
	*/
	GameDirector();

	/*
	* Function: void GameDirector::checkSpawns(Timer& timer)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Checks if its time to spawn another target, if so, makes target appear.
	* Input parameters: Timer& timer
	* Returns: void
	* Preconditions: Timer& timer must be running, along with the game. Tarray must be initalized.
	* Postconditions: Modifies target objects, modifies timeAtNextSpawn data member.
	*/
	void checkSpawns(Timer& timer);

	/*
	* Function: bool GameDirector::checkClick(sf::RenderWindow& thisWindow, sf::Vector2f& mouse, Player& p)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Called when player clicks, checks if player successfully it a spawned target.
	* Input parameters: sf::RenderWindow& thisWindow, sf::Vector2f& mouse, Player& p
	* Returns: bool
	* Preconditions: sf::RenderWindow& thisWindow refers to the current open window, sf::Vector2f& mouse refers to the location of the mouse
	*				 Player& p refers to the current player object. Tarray must be initalized.
	* Postconditions: Returns true if hit target, false otherwise. Modifies targets.
	*/
	bool checkClick(sf::RenderWindow& thisWindow, sf::Vector2f& mouse, Player& p);

	/*
	* Function: void GameDirector::renderTargets(sf::RenderWindow& thisWindow)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Goes through all targets in Tarray and renders each spawned target to screen.
	* Input parameters: sf::RenderWindow& thisWindow
	* Returns: void 
	* Preconditions: sf::RenderWindow& thisWindow refers to the current open window, the game has started. Tarray must be initalized.
 	* Postconditions: Renders targets to screen.
	*/
	void renderTargets(sf::RenderWindow& thisWindow);

	/*
	* Function: void GameDirector::renderCrosshair(sf::RenderWindow& thisWindow)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Renders crosshair to the location of the mouse pointer.
	* Input parameters: sf::RenderWindow& thisWindow
	* Returns: void
	* Preconditions: sf::RenderWindow& thisWindow refers to the current open window.
	* Postconditions: Renders crosshair asset to screen.
	*/
	void renderCrosshair(sf::RenderWindow& thisWindow);

	/*
	* Function: void GameDirector::runTargetUpdates(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Goes through all spawned targets in Tarray and triggers each update function.
	* Input parameters: void
	* Returns: void
	* Preconditions: Game must be running. Tarray must be initalized.
	* Postconditions: Runs each spawned target's update function.
	*/
	void runTargetUpdates(void);

	/*
	* Function: bool GameDirector::isAllTargetsDestroyed(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Returns true if all targets are destroyed, false otherwise.
	* Input parameters: void
	* Returns: bool
	* Preconditions: Tarray must be initalized.
	* Postconditions: Returns true if all targets are destroyed, false otherwise.
	*/
	bool isAllTargetsDestroyed(void);

	/*
	* Function: bool GameDirector::isAllTargetsSpawned(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Returns true if all targets are spawned, false otherwise.
	* Input parameters: void 
	* Returns: bool
	* Preconditions: Tarray must be initalized.
	* Postconditions: Returns true if all targets are spawned, false otherwise.
	*/
	bool isAllTargetsSpawned(void);

	/*
	* Function: void GameDirector::setTarray(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Initalizes all indexes of Tarray to target objects.
	* Input parameters: void
	* Returns: void
	* Preconditions: N/A
	* Postconditions: Initalizes indexs of Tarray, creates memory on heap.
	*/
	void setTarray(void);

	/*
	* Function: void GameDirector::reset(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Runs all operations to reset GameDirector for new game.
	* Input parameters: void
	* Returns: void 
	* Preconditions: Game is not running. 
 	* Postconditions: Sets all Tarray targets to destroyed, modifies timeAtNextSpawn.
	*/
	void reset(void);

	/*
	* Function: void GameDirector::destroyAllTargets(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Sets all targets in Tarray to destroyed.
	* Input parameters: void 
	* Returns: void
	* Preconditions: N/A
	* Postconditions: Sets all targets in Tarray isDestroyed value to true.
	*/
	void destroyAllTargets(void);

private:
	Target* Tarray[15];
	float timeAtNextSpawn;
};



#endif