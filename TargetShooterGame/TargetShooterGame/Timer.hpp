#ifndef TIMER
#define TIMER

#include "SFML/Graphics.hpp"
#include "SFML/system.hpp"
#include <sstream>

class Timer : public sf::Clock
{
public:
	Timer() : text(font, "Hello World!", 50)
	{
		font.openFromFile("Assets\\fonts\\TTT-Regular.otf");//refers to directory path from project 

		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(0, 0));
	}

	sf::Text& getText(void);
	void setTextStringFromFloat(const float& f);
	//t.setTextStringFromFloat(t.getElapsedTime().asSeconds());
	//window.draw(t.getText());
//because its also a Clock, its timer starts when its initalized, also has functions stop(), start(), restart(), 
private:
	sf::Font font;//text needs to keep reference of font, so is data member
	sf::Text text;
};

#endif 