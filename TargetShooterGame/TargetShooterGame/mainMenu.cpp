#include "mainMenu.hpp"

void MainMenu::drawMenu(sf::RenderWindow& win) const
{
	win.draw(this->title);
	win.draw(this->subtitle);
	win.draw(this->button);
	win.draw(this->ButtonText);
	win.draw(this->ruleButton);
	win.draw(this->RuleButtonText);

}

void MainMenu::drawRules(sf::RenderWindow& win) const
{
	win.draw(this->backToMenu);
	win.draw(this->BackToMenuText);
	win.draw(this->rule1);
	win.draw(this->rule2);
	win.draw(this->rule3);
	win.draw(this->rule1T);
	win.draw(this->rule2T);
	win.draw(this->rule3T);
}

void MainMenu::setinMenu(bool newBool)
{
	this->inMenu = newBool;
}

void MainMenu::setinRules(bool newBool)
{
	this->inRules = newBool;
}

bool MainMenu::getinMenu(void)
{
	return this->inMenu;
}

bool MainMenu::getInRules(void)
{
	return this->inRules;
}

sf::CircleShape& MainMenu::getButton(void)
{
	return this->button;
}

sf::CircleShape& MainMenu::getRuleButton(void)
{
	return this->ruleButton;
}

sf::CircleShape& MainMenu::getBackButton(void)
{
	return this->backToMenu;
}
