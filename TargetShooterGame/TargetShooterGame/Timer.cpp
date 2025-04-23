/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: Content file that will include the definitons for
* the Timer.hpp file.
*****************************************************************/

#include "Timer.hpp"


sf::Text& Timer::getText(void)
{
	return this->text;
}

void Timer::setTextStringFromFloat(const float& f)
{
	std::ostringstream s;
	s << f;
	sf::String str(s.str());
	this->text.setString(str);
}

