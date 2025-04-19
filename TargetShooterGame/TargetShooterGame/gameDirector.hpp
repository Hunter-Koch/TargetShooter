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
	void checkClick(sf::RenderWindow& thisWindow, sf::Vector2f& mouse, Player& p);
	void renderTargets(sf::RenderWindow& thisWindow);

	void renderCrosshair(sf::RenderWindow& thisWindow);
	void runTargetUpdates(void);

	bool isAllTargetsDestroyed(void);
	bool isAllTargetsSpawned(void);

	void setTarray(void);

private:
	Target* Tarray[15];
	float timeAtNextSpawn;


	//plan:
	//have array of target ptr's that represents all of the total targets that can appear at once
	//let it have access to the timer, and on random time interval, it picks a target from the array and displays it, 
	//targets are not displayed and their position is offscreen when they are destoryed/not spawned
	//has function that checks bounds of all spawned fucntions to see if mouse is in bounds when clicked /checks for another interval if time for being out too long has occurred
	//target returns to destoryed state and chooses another random time interval to spawn again
};



#endif