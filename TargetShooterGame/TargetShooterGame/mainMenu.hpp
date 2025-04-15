#include "miscFunctions.hpp"

class MainMenu
{
public:
	MainMenu() : title(font, "TARGET GAME", 50), ButtonText(font, "PLAY GAME", 50)//Text(Font& font, sf::string text, int maxCharacters)
	{
		font.openFromFile("Fonts\\TTT-Regular.otf");

		title.setFont(font);
		title.setFillColor(sf::Color::White);
		title.setPosition(sf::Vector2f(430, 0));
		title.scale(sf::Vector2f(1.5, 1.5));

		ButtonText.setFont(font);
		ButtonText.setFillColor(sf::Color::White);
		ButtonText.setPosition(sf::Vector2f(520, 310));

		button.setFillColor(sf::Color::Cyan);
		button.setPosition(sf::Vector2f(490, 200));
		button.setRadius(150);
	}

	void drawMenu(sf::RenderWindow& win) const;
	void setinMenu(bool newBool);
	bool getinMenu(void);
	sf::CircleShape& getButton(void);

private:
	bool inMenu = true;
	sf::Font font;
	sf::Text title;
	sf::Text ButtonText;
	sf::CircleShape button;
};