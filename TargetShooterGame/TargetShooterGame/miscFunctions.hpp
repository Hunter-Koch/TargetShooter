/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 20, 2025
* Description: A header file for miscellanous functions, this will be used
* to keep function prototypes for functions to be used in other places, along
* with common library imports.
*****************************************************************/

#ifndef FUNCT
#define FUNCT

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SFML/Graphics.hpp"
#include <string>
#include "target.hpp"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


using std::cout;
using std::endl;
using std::ostream;
using sf::Text;

/*
* Function: int randRange(int min, int max)//lowest val is 0
* Date Created: 4/15/2025
* Date Last Modified: 4/15/2025
* Description: Takes in a min and max and returns a number between them.
* Input parameters: int min, int max
* Returns: int 
* Preconditions: int min must be lower than int max. 
* Postconditions: returns int value between int min and int max
*/
int randRange(int min, int max);







#endif