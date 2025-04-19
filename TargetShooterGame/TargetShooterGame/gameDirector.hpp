#ifndef DIRECT
#define DIRECT

#include "healthyTarget.hpp"
#include "Timer.hpp"
#include "duckTarget.hpp"
#include "floatingTarget.hpp"
#include "negativeTarget.hpp"
#include "fastTarget.hpp"
#include "smallTarget.hpp"
#include "Player.hpp"

class GameDirector
{
public:
	GameDirector();

	void checkSpawns(Timer& timer);
	//returns true if hit target, false otherwise
	bool checkClick(sf::RenderWindow& thisWindow, sf::Vector2f& mouse, Player& p);
	void renderTargets(sf::RenderWindow& thisWindow);

	void renderCrosshair(sf::RenderWindow& thisWindow);
	void runTargetUpdates(void);

	bool isAllTargetsDestroyed(void);
	bool isAllTargetsSpawned(void);

	void setTarray(void);
	void reset(void);
	void destroyAllTargets(void);

private:
	Target* Tarray[15];
	float timeAtNextSpawn;
};



#endif