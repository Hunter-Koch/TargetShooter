#ifndef STATS
#define STATS

#include "Target.hpp"


class Stats
{
public:
	Stats();

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

	void updateText(void);
	sf::Text& getText(void);

	void resetStats(void);

private:
	int hitTargets;
	int totalShots;
	int missedShots;
	float accuracy;
	int totalPoints;
	sf::Text text;
	sf::Font font;
};

#endif