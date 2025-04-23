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
#include "negativeTarget.hpp"
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
	MainMenu() : title(font, "TARGET SHOOTER", 50), ButtonText(font, "PLAY GAME", 50), subtitle(font, "Developed by Hunter Koch, Alexis Maria, and Reed Williams", 50),    //Text(Font& font, sf::string text, int maxCharacters)
	RuleButtonText(font, "RULES", 20), BackToMenuText(font, "BACK TO MENU", 20), rule1(font, "Click on targets to shoot them", 50),
		rule2(font, "Dont shoot cats", 50), rule3(font, "Shoot as many targets as you \ncan before time runs out"),
		rule3T(font, "2.18901", 50)
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

		inRules = false;
		ruleButton.setPosition(sf::Vector2f(1130, 580));
		ruleButton.setRadius(50);

		backToMenu.setPosition(sf::Vector2f(1130, 580));
		backToMenu.setRadius(50);

		RuleButtonText.setFont(font);
		RuleButtonText.setFillColor(sf::Color::Black);
		RuleButtonText.setPosition(sf::Vector2f(1160, 690));
		RuleButtonText.scale(sf::Vector2f(1, 1));


		//rule menu text
		BackToMenuText.setFont(font);
		BackToMenuText.setFillColor(sf::Color::Black);
		BackToMenuText.setPosition(sf::Vector2f(1160, 690));
		BackToMenuText.scale(sf::Vector2f(1, 1));

		rule1.setFont(font);
		rule1.setFillColor(sf::Color::Black);
		rule1.setPosition(sf::Vector2f(200, 190));
		rule1.scale(sf::Vector2f(1, 1));

		rule2.setFont(font);
		rule2.setFillColor(sf::Color::Black);
		rule2.setPosition(sf::Vector2f(200, 290));
		rule2.scale(sf::Vector2f(1, 1));

		rule3.setFont(font);
		rule3.setFillColor(sf::Color::Black);
		rule3.setPosition(sf::Vector2f(200, 390));
		rule3.scale(sf::Vector2f(1.25, 1.25));

		rule1T.setPosition(sf::Vector2f(805, 155));
		rule1T.setRadius(70);

		rule2T.setPosition(sf::Vector2f(550, 260));
		rule2T.setRadius(70);

		rule3T.setFont(font);
		rule3T.setFillColor(sf::Color::White);
		rule3T.setPosition(sf::Vector2f(680, 390));
		rule3T.scale(sf::Vector2f(1.2, 1.2));
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
	* Function: void MainMenu::drawRules(sf::RenderWindow& win) const
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Takes in the render window and prints the rules assets to the screen.
	* Input parameters: sf::RenderWindow& win
	* Returns: void
	* Preconditions: sf::RenderWindow& win must refer to the current open window, game must not be running. Must be in rules menu. InRules data member must be true.
	* Postconditions: Renders Rules assets to screen.
	*/
	void drawRules(sf::RenderWindow& win) const;

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
	* Function: void MainMenu::setInRules(bool newBool)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Setter for inRules data member.
	* Input parameters: bool newBool
	* Returns: void
	* Preconditions: N/A
	* Postconditions: Modifies inRules data member to value of bool newBool.
	*/
	void setinRules(bool newBool);

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
	* Function: bool MainMenu::getInRules(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for inRules data member.
	* Input parameters: void
	* Returns: bool
	* Preconditions: N/A
	* Postconditions: Returns value of inRules data member.
	*/
	bool getInRules(void);

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

	/*
	* Function: sf::CircleShape& MainMenu::getRuleButton(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for rulebutton data member.
	* Input parameters: void
	* Returns: sf::CircleShape&
	* Preconditions: N/A
	* Postconditions: Returns refrence of rulebutton data member.
	*/
	sf::CircleShape& getRuleButton(void);

	/*
	* Function: sf::CircleShape& MainMenu::getBackButton(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for backtoMenu data member.
	* Input parameters: void
	* Returns: sf::CircleShape&
	* Preconditions: N/A
	* Postconditions: Returns refrence of backtoMenu data member.
	*/
	sf::CircleShape& getBackButton(void);

private:
	bool inMenu;
	bool inRules;
	sf::Font font;
	sf::Text title;
	sf::Text subtitle;
	sf::Text ButtonText;
	sf::Text RuleButtonText;
	sf::Text BackToMenuText;
	Target button;
	Target ruleButton;
	Target backToMenu;

	sf::Text rule1;
	sf::Text rule2;
	sf::Text rule3;
	Target rule1T;
	negativeTarget rule2T;
	sf::Text rule3T;

};