#include "miscFunctions.hpp"
#include "Target.hpp"

class MainMenu
{
public:
	MainMenu() : title(font, "TARGET SHOOTER", 50), ButtonText(font, "PLAY GAME", 50), subtitle(font,"Developed by Hunter Koch, Alexis Maria, and Reed Williams", 50)//Text(Font& font, sf::string text, int maxCharacters)
	{
		font.openFromFile("Assets\\fonts\\TTT-Regular.otf");

		title.setFont(font);
		title.setFillColor(sf::Color::White);
		title.setPosition(sf::Vector2f(400, 0));
		title.scale(sf::Vector2f(1.5, 1.5));

		subtitle.setFont(font);
		subtitle.setFillColor(sf::Color::White);
		subtitle.setPosition(sf::Vector2f(230, 70));
		subtitle.scale(sf::Vector2f(0.75, 0.75));

		ButtonText.setFont(font);
		ButtonText.setFillColor(sf::Color::White);
		ButtonText.setPosition(sf::Vector2f(520, 480));

		button.setPosition(sf::Vector2f(490, 200));
		button.setRadius(150);
		inMenu = true;
	}

	void drawMenu(sf::RenderWindow& win) const;
	void setinMenu(bool newBool);
	bool getinMenu(void);
	sf::CircleShape& getButton(void);

private:
	bool inMenu;
	sf::Font font;
	sf::Text title;
	sf::Text subtitle;
	sf::Text ButtonText;
	Target button;
};