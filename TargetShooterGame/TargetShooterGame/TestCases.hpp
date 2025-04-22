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

void runTestCases();

class Test
{
public:

	void testNegativeTarget();

	void testAddTime();

	void testTargetDisappear();

	void testGameEnd();

private:

};



#endif

