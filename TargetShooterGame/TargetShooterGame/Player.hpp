#ifndef PLAYER
#define PLAYER

#include <SFML/Graphics.hpp>
#include "Stats.hpp"
#include <SFML/system.hpp>

class Player 
{
public:
	Player() : text(pfont, "temp", 50)
	{
		pfont.openFromFile("Assets\\fonts\\TTT-Regular.otf");//refers to directory path from project 
		this->totalTime = 10;

		text.setFont(pfont);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(0, 0));
	}

	int getTotalTime();
	void setTotalTime(int newTime);
	void AddToTime(int addToTime);
	Text& getpCurrentTime(float currentTimerinSeconds);

private:
	int totalTime;
	Stats playerStats;
	Text text;
	sf::Font pfont;
};

#endif 