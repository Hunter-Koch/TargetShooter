#include "Stats.hpp"

Stats::Stats()
{
	this->missedTargets = 0;
	this->totalShots = 0;
	this->missedShots = 0;
	this->accuracy = 0.0;
	this->totalPoints = 0;
	this->hitTargets = 0;
}

void Stats::incrementMissedTargets()
{
	this->missedTargets++;
}

int Stats::getMissedTargets()
{
	return this->missedTargets;
}

void Stats::incrementhitTargets()
{
	this->hitTargets++;
}

int Stats::getHitTargets()
{
	return this->hitTargets;
}

void Stats::incrementTotalShots()
{
	this->totalShots++;
}

int Stats::getTotalShots()
{
	return this->totalShots;
}

void Stats::incrementMissedShots()
{
	this->missedShots++;
}

int Stats::getMissedShots()
{
	return missedShots; 
}

void Stats::calculateAccuracy()
{
	//((total - missed /total) * 100)
	this->accuracy = ((totalShots - missedShots) / totalShots) * 100;
}

float Stats::getAccuracy()
{
	calculateAccuracy();
	return this->accuracy;
}

void Stats::updateTotalPoints(int addedPoints)
{
	this->totalPoints += addedPoints;
}

int Stats::getTotalPoints()
{
	return this->totalPoints;
}
