/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 20, 2025
* Description: A header file for Stats, this will be used to record the 
* statistics for the player.
*****************************************************************/

#ifndef STATS
#define STATS

#include "Target.hpp"

class Stats
{
public:

	/*
	* Function: Stats::Stats() : text(this->font, "TEMP", 100)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Default constructor for Stats.
	* Input parameters: void
	* Returns: N/A
	* Preconditions: Stats object has to be created.
	* Postconditions: Initalizes data members, opens proper asset files.
	*/
	Stats();

	/*
	* Function: void Stats::incrementhitTargets()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Incremements hitTargets data member by 1.
	* Input parameters: void
	* Returns: void
	* Preconditions: Should be called after player has hit a target.  
	* Postconditions: Modifies hitTargets data member.
	*/
	void incrementhitTargets();

	/*
	* Function: int Stats::getHitTargets()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for hitTargets data member.
	* Input parameters: void
	* Returns: int
	* Preconditions: N/A
	* Postconditions: Returns value of hitTargets data member.
	*/
	int getHitTargets();

	/*
	* Function: void Stats::incrementTotalShots()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Incremements totalShots data member by 1.
	* Input parameters: void
	* Returns: void
	* Preconditions: Should be called after player has clicked in game.  
	* Postconditions: Modifies totalShots data member.
	*/
	void incrementTotalShots();

	/*
	* Function: int Stats::getTotalShots()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for totalShots data member.
	* Input parameters: void
	* Returns: int
	* Preconditions: N/A
	* Postconditions: Returns value of totalShots data member.
	*/
	int getTotalShots();

	/*
	* Function: void Stats::incrementMissedShots()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Incremements missedShots data member by 1.
	* Input parameters: void
	* Returns: void 
	* Preconditions: Should be called after player has clicked and missed a target in game.  
	* Postconditions: Modifies missedShots data member.
	*/
	void incrementMissedShots();

	/*
	* Function: int Stats::getMissedShots()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for missedShots data member.
	* Input parameters: void
	* Returns: int
	* Preconditions: N/A
	* Postconditions: Returns value of missedShots data member.
	*/
	int getMissedShots();

	/*
	* Function: void Stats::calculateAccuracy()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Calculates accuracy based on values of missedShots and totalShots data members.
	* Input parameters: void
	* Returns: void
	* Preconditions: totalShots can't be zero.
	* Postconditions: Modifies accuracy data member.
	*/
	void calculateAccuracy();

	/*
	* Function: float Stats::getAccuracy()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for accuracy data member.
	* Input parameters: void
	* Returns: float
	* Preconditions: N/A
	* Postconditions: Returns value of accuracy data member. 
	*/
	float getAccuracy();

	/*
	* Function: void Stats::updateTotalPoints(int addedPoints)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Adds value of points to totalPoints data member.
	* Input parameters: int addedPoints
	* Returns: void
	* Preconditions: int addedPoints can't be zero.
	* Postconditions: Modifies totalPoints data member.
	*/
	void updateTotalPoints(int addedPoints);

	/*
	* Function: int Stats::getTotalPoints()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for accuracy data member.
	* Input parameters: void
	* Returns: int 
	* Preconditions: N/A
	* Postconditions: Returns value of totalPoints data member. 
	*/
	int getTotalPoints();

	/*
	* Function: void Stats::updateText(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Modifies text data member with the current stats from other data members.
	* Input parameters: void 
	* Returns: void
	* Preconditions: N/A
	* Postconditions: Modifies sf::String in text data member.
	*/
	void updateText(void);

	/*
	* Function: sf::Text& Stats::getText(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for text data member.
	* Input parameters: void 
	* Returns: sf::Text& 
	* Preconditions: text data member's sf::String must be updated.
	* Postconditions: Returns reference to text data member.
	*/
	sf::Text& getText(void);

	/*
	* Function: void Stats::resetStats(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Sets stats to default values.
	* Input parameters: void 
	* Returns: void 
	* Preconditions: Game must not be running. 
  	* Postconditions: Modifies hitTargets, totalShots, missedShots, accuracy, and totalPoints
	*					data member to default values.
	*/
	void resetStats(void);

private:
	int hitTargets;
	int totalShots;
	int missedShots;
	float accuracy;
	int totalPoints;
	sf::Text text;
	sf::Font font;
};

#endif