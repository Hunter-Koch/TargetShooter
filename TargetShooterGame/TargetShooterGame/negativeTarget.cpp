/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: Content file that will include the definitons for
* the negativeTarget.hpp file.
*****************************************************************/

#include "negativeTarget.hpp"

void negativeTarget::appear()
{
	this->restartTimer();
	this->setPosition(sf::Vector2f(randRange(0, 1000), randRange(0, 500)));
	this->playAppearEffect();
	this->setIsDestryed(false);
}

void negativeTarget::destroy()
{
	this->stopTimer();
	this->setPosition(sf::Vector2f(0, 1000));
	this->playDestroyEffect();
	this->setIsDestryed(true);
}