#include "Stats.hpp"

Stats::Stats() : text(this->font, "TEMP", 100)
{
	this->totalShots = 0;
	this->missedShots = 0;
	this->accuracy = 0.0;
	this->totalPoints = 0;
	this->hitTargets = 0;
	updateText();
	font.openFromFile("Assets\\fonts\\TTT-Regular.otf");//refers to directory path from project 
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(0, 0));
	text.scale(sf::Vector2f(0.2, 0.2));
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
	if (this->totalShots != 0)
	{
		this->accuracy = ((((float)totalShots - (float)missedShots) / (float)totalShots) * 100);
	}
	else
	{
		this->accuracy = 0.0f;
	}
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

void Stats::updateText(void)
{
	std::ostringstream s;
	s << "Last Run Stats:" <<
		"\nTotal Shots: " << totalShots << 
		"\nMissed Shots: " << missedShots << 
		"\nAccuracy: " << getAccuracy() << 
		"%\nTargets Hit: " << hitTargets << 
		"\nTotal Points: " << totalPoints;
	sf::String str(s.str());
	this->text.setString(str);
}

sf::Text& Stats::getText(void)
{
	this->updateText();
	return this->text;
}

void Stats::resetStats(void)
{
	this->totalShots = 0;
	this->missedShots = 0;
	this->accuracy = 0.0;
	this->totalPoints = 0;
	this->hitTargets = 0;
}

