/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: A header file for both the test cases and the test class.
* This will store the 5 test cases we are writing.
*****************************************************************/

#ifndef TEST
#define TEST


#include "negativeTarget.hpp"
#include "duckTarget.hpp"
#include "floatingTarget.hpp"
#include "healthyTarget.hpp"
#include "Target.hpp"
#include "fastTarget.hpp"
#include "iostream"
#include "Player.hpp"
#include "smallTarget.hpp"
#include "gameDirector.hpp"


/*
* Function: void runTestCases();
* Date Created: 4/20/2025
* Date Last Modified: 4/22/2025
* Description: runs all test cases
* Input parameters: void
* Returns: void
* Preconditions: All test cases must be implemented and functional.
* Postconditions: displays results of the test cases
*/
void runTestCases();

class Test
{
public:

	/*
* Function: void testNegativeTarget()
* Date Created: 4/20/2025
* Date Last Modified: 4/22/2025
* Description: Tests to make sure negative target correctly subtracts time
* Input parameters: void
* Returns: void
* Preconditions: negative target must be functional
* Postconditions: displays result of test case
*/
	void testNegativeTarget();


	/*
* Function: void testAddTime()
* Date Created: 4/20/2025
* Date Last Modified: 4/22/2025
* Description: Tests to make sure hitting targets adds time
* Input parameters: void
* Returns: void
* Preconditions: targets and score logic must be functional
* Postconditions: displays results of test case
*/
	void testAddTime();


	/*
* Function: void testTargetDisappear();
* Date Created: 4/20/2025
* Date Last Modified: 4/22/2025
* Description: Tests to make sure targets disappear after their timer has run out
* Input parameters: void
* Returns: void
* Preconditions: target must have a valid setTimeAlive
* Postconditions: displays results of test case
*/
	void testTargetDisappear();


	/*
* Function: void runGameEnd()
* Date Created: 4/20/2025
* Date Last Modified: 4/22/2025
* Description: Tests to make sure the game ends after the timer has run out
* Input parameters: void
* Returns: void
* Preconditions: timer and game loop must be functional
* Postconditions: displays result of test case
*/
	void testGameEnd();


	/*
* Function: void testUninitialized();
* Date Created: 4/20/2025
* Date Last Modified: 4/22/2025
* Description: tests to make sure gameDirector's Tarray is initialized
* Input parameters: void
* Returns: void
* Preconditions: gameDirector must have function isArrayInitialized()
* Postconditions: displays result of test case
*/
	void testUninitialized();

private:

};



#endif

