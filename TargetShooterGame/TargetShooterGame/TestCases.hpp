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

