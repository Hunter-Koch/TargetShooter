#ifndef PLAYER
#define PLAYER

#include <SFML/Graphics.hpp>
#include "Stats.hpp"
#include <SFML/system.hpp>

class Player 
{
public:
	/*
	* Function: Player() : text(pfont, "temp", 50)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Default Constructor for class Player.
	* Input parameters: void
	* Returns: N/A
	* Preconditions: Player object has to be created.
	* Postconditions: Initalizes data members and loads proper files, sets proper position and color for visial assets.
	*/
	Player() : text(pfont, "temp", 50)
	{
		pfont.openFromFile("Assets\\fonts\\TTT-Regular.otf");//refers to directory path from project 
		this->totalTime = 10;

		text.setFont(pfont);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(0, 0));
	}

	/*
	* Function: int Player::getTotalTime()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for totalTime data member.
	* Input parameters: void
	* Returns: int
	* Preconditions: N/A
	* Postconditions: Returns value of totalTime data member.
	*/
	int getTotalTime();

	/*
	* Function: void Player::setTotalTime(int newTime)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Setter for totalTime data member.
	* Input parameters: int newTime
	* Returns: void
	* Preconditions: N/A
	* Postconditions: Modifies value of totalTime data member to int newTime.
	*/
	void setTotalTime(int newTime);

	/*
	* Function: void Player::AddToTime(int addToTime)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Adds int addToTime to totalTime data member.
	* Input parameters: int addToTime
	* Returns: void
	* Preconditions: N/A
	* Postconditions: Modifies value of totalTime data member by adding int AddToTime.
	*/
	void AddToTime(int addToTime);

	/*
	* Function: Text& Player::getpCurrentTime(float currentTimerinSeconds)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Takes in current time as float, converts to sf::String and sets it to text data member.
	* Input parameters: float currentTimerinSeconds
	* Returns: Text&
	* Preconditions: float currentTimerinSeconds must the current time from game.
	* Postconditions: Modifies text's sf::String to value of float currentTimerinSeconds.
	*/
	Text& getpCurrentTime(float currentTimerinSeconds);

	/*
	* Function: Text& Player::getStatsAsText(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for Stat's text class.
	* Input parameters: void
	* Returns: Text&
	* Preconditions: N/A
	* Postconditions: Returns refrence to Stat's text class.
	*/
	Text& getStatsAsText(void);

	/*
	* Function: void Player::resetPlayerStats(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Calls the stat's class's reset stats data member.
	* Input parameters: void
	* Returns: void
	* Preconditions: N/A
	* Postconditions: Returns values of playerStats data member to default.
	*/
	void resetPlayerStats(void);

	/*
	* Function: Stats& Player::getStats(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for playerStats data member.
	* Input parameters: void
	* Returns: Stats&
	* Preconditions: N/A
	* Postconditions: Returns reference of playerStats data member.
	*/
	Stats& getStats(void);
private:
	int totalTime;
	Stats playerStats;
	Text text;
	sf::Font pfont;
};

#endif 