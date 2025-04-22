/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: Content file that will include the definitons for
* the TestCases.hpp file.
*****************************************************************/

#include "TestCases.hpp"

void runTestCases()
{
	Test t;
	t.testNegativeTarget();
	t.testAddTime();
	t.testTargetDisappear();
	t.testGameEnd();
}

void Test::testNegativeTarget()
{
	Player p1;
	negativeTarget target;

	p1.setTotalTime(10);
	target.setScoreAwarded(-3);

	target.destroy();

	p1.AddToTime(target.getScoreAwarded());

	int realTime = p1.getTotalTime();
	int TimeExpected = 7;

	if (realTime == TimeExpected)
	{
		std::cout << "Negative Target test passed" << std::endl;
	}
	else
	{
		std::cout << "Negative Target test failed" << std::endl;
	}
}

void Test::testAddTime()
{
	Player p;
	fastTarget fast;
	duckTarget duck;
	floatingTarget floating;
	HealthyTarget healthy;
	Target target;
	smallTarget small;

	p.setTotalTime(10);

	fast.destroy();
	duck.destroy();
	floating.destroy();
	healthy.destroy();
	target.destroy();
	small.destroy();

	p.AddToTime(fast.getScoreAwarded());
	p.AddToTime(duck.getScoreAwarded());
	p.AddToTime(floating.getScoreAwarded());
	p.AddToTime(healthy.getScoreAwarded());
	p.AddToTime(target.getScoreAwarded());
	p.AddToTime(small.getScoreAwarded());


	int realTime = p.getTotalTime();
	int timeExpected = 20;


	if (realTime == timeExpected)
	{
		std::cout << "Add Time test passed" << std::endl;
	}
	else
	{
		std::cout << "Add Time test failed" << std::endl;
	}
}



void Test::testTargetDisappear()
{
	Target target; // live for 3 seconds

	target.setTimeAlive(1);
	target.appear();

	Timer t;

	while (t.getElapsedTime().asSeconds() <= 1)
	{
		target.update();
	}

	bool targetGone = target.getIsDestroyed();

	if (targetGone)
	{
		std::cout << "Target Disappearance test passed" << std::endl;
	}
	else
	{
		std::cout << "Target Disappearance test failed" << std::endl;
	}
}

void Test::testGameEnd()
{
	Timer timer;
	Player p;
	p.setTotalTime(0);

	bool gameEnd = false;

	if (p.getTotalTime() <= 0)
	{
		gameEnd = true;
	}

	if (gameEnd)
	{
		std::cout << "Game End test passed" << std::endl;
	}
	else
	{
		std::cout << "Game End test failed" << std::endl;
	}
}