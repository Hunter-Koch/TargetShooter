#include "TestCases.hpp"



void testNegativeTarget()
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