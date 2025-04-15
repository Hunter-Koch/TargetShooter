#include "mainMenu.hpp"

void MainMenu::drawMenu(sf::RenderWindow& win) const
{
	win.draw(this->title);
	win.draw(this->button);
	win.draw(this->ButtonText);
}

void MainMenu::setinMenu(bool newBool)
{
	this->inMenu = newBool;
}

bool MainMenu::getinMenu(void)
{
	return this->inMenu;
}

sf::CircleShape& MainMenu::getButton(void)
{
	return this->button;
}
