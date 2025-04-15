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

