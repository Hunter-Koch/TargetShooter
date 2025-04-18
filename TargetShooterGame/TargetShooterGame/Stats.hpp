#ifndef  STATS
#define STATS

#include "Target.hpp"


class Stats
{
public:
	Stats();

	void incrementMissedTargets();
	int getMissedTargets();

	void incrementhitTargets();
	int getHitTargets();

	void incrementTotalShots();
	int getTotalShots();

	void incrementMissedShots();
	int getMissedShots();

	void calculateAccuracy();
	float getAccuracy();

	void updateTotalPoints(int addedPoints);
	int getTotalPoints();

private:
	int missedTargets;
	int hitTargets;
	int totalShots;
	int missedShots;
	float accuracy;
	int totalPoints;
};

#endif