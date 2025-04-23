/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: Header file that includes the base GameObject class.
* This class will be inherited from target and its variants, include a
* pure virtual update function for use in gameDirector.hpp.
*****************************************************************/

#pragma once
#ifndef OBJ
#define OBJ

#include "miscFunctions.hpp"
#include <string>
#include <SFML/Graphics.hpp>

class GameObject// : public sf::Sprite
{
public:

	/*
	* Function:	virtual void update() = 0;
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Pure virtual function to be overloaded in each target class.
	* Input parameters: void
	* Returns: void
	* Preconditions: N/A
	* Postconditions: N/A
	*/
	virtual void update() = 0;
};

#endif 