/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 20, 2025
* Description: A header file for Timer, this will be used to both 
* record the time targets are alive and if the game has ended.
*****************************************************************/

#ifndef TIMER
#define TIMER

#include "SFML/Graphics.hpp"
#include "SFML/system.hpp"
#include <sstream>

class Timer : public sf::Clock
{
public:

	/*
	* Function: Timer() : text(font, "Hello World!", 50)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Default constructor for Timer.
	* Input parameters: void
	* Returns: N/A
	* Preconditions: Timer object has to be created.
	* Postconditions: Initalizes data members and opens proper asset files.
	*/
	Timer() : text(font, "Hello World!", 50)
	{
		font.openFromFile("Assets\\fonts\\TTT-Regular.otf");//refers to directory path from project 

		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(0, 0));
	}

	/*
	* Function: sf::Text& Timer::getText(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for text data member.
	* Input parameters: void
	* Returns: sf::Text&
	* Preconditions: N/A
	* Postconditions: Returns reference to text data member.
	*/
	sf::Text& getText(void);

	/*
	* Function: void Timer::setTextStringFromFloat(const float& f)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Takes in a float value and sets text to that float value.
	* Input parameters: const float& f
	* Returns: void
	* Preconditions: f must represent the time in Timer.
	* Postconditions: Sets sf::String in text data member to f.
	*/
	void setTextStringFromFloat(const float& f);


	//examples on how to use
	//t.setTextStringFromFloat(t.getElapsedTime().asSeconds());
	//window.draw(t.getText());
	//because its also a Clock, its timer starts when its initalized, also has functions stop(), start(), restart(), 
private:
	sf::Font font;//text needs to keep reference of font, so is data member
	sf::Text text;
};

#endif 