/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 20, 2025
* Description: A header file for MainMenu, this will be used to print 
* the main menu and get user input for the menu.
*****************************************************************/

#include "miscFunctions.hpp"
#include "Target.hpp"

class MainMenu
{
public:
	/*
	* Function: MainMenu() : title(font, "TARGET SHOOTER", 50), ButtonText(font, "PLAY GAME", 50), 
	*			subtitle(font,"Developed by Hunter Koch, Alexis Maria, and Reed Williams", 50)//Text(Font& font, sf::string text, int maxCharacters)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Default constructor for MainMenu.
	* Input parameters: void
	* Returns: N/A
	* Preconditions: MainMenu object has to be created.
	* Postconditions: Initalizes data members, opens proper asset files.
	*/
	MainMenu() : title(font, "TARGET SHOOTER", 50), ButtonText(font, "PLAY GAME", 50), subtitle(font,"Developed by Hunter Koch, Alexis Maria, and Reed Williams", 50)//Text(Font& font, sf::string text, int maxCharacters)
	{
		font.openFromFile("Assets\\fonts\\TTT-Regular.otf");

		title.setFont(font);
		title.setFillColor(sf::Color::Black);
		title.setPosition(sf::Vector2f(400, 0));
		title.scale(sf::Vector2f(1.5, 1.5));

		subtitle.setFont(font);
		subtitle.setFillColor(sf::Color::Black);
		subtitle.setPosition(sf::Vector2f(230, 70));
		subtitle.scale(sf::Vector2f(0.75, 0.75));

		ButtonText.setFont(font);
		ButtonText.setFillColor(sf::Color::Black);
		ButtonText.setPosition(sf::Vector2f(520, 480));

		button.setPosition(sf::Vector2f(490, 200));
		button.setRadius(150);
		inMenu = true;
	}

	/*
	* Function: void MainMenu::drawMenu(sf::RenderWindow& win) const
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Takes in the render window and prints the main menu assets to the screen.
	* Input parameters: sf::RenderWindow& win
	* Returns: void
	* Preconditions: sf::RenderWindow& win must refer to the current open window, game must not be running.
	* Postconditions: Renders main menu assets to screen.
	*/
	void drawMenu(sf::RenderWindow& win) const;

	/*
	* Function: void MainMenu::setinMenu(bool newBool)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Setter for inMenu data member.
	* Input parameters: bool newBool
	* Returns: void
	* Preconditions: bool newBool must refer to the current state of the game.
	* Postconditions: Modifies inMenu data member to value of newBool.
	*/
	void setinMenu(bool newBool);

	/*
	* Function: bool MainMenu::getinMenu(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for inMenu data member.
	* Input parameters: void 
	* Returns: bool 
	* Preconditions: N/A
 	* Postconditions: Returns value of inMenu data member.
	*/
	bool getinMenu(void);

	/*
	* Function: sf::CircleShape& MainMenu::getButton(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for button data member.
	* Input parameters: void
	* Returns: sf::CircleShape&
	* Preconditions: N/A
	* Postconditions: Returns refrence of button data member.
	*/
	sf::CircleShape& getButton(void);

private:
	bool inMenu;
	sf::Font font;
	sf::Text title;
	sf::Text subtitle;
	sf::Text ButtonText;
	Target button;
};