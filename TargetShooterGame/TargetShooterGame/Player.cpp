/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: Content file that will include the definitons for
* the Player.hpp file.
*****************************************************************/

#include "Player.hpp"

int Player::getTotalTime()
{
    return this->totalTime;
}

void Player::setTotalTime(int newTime)
{
    this->totalTime = newTime;
}

void Player::AddToTime(int addToTime)
{
    this->totalTime += addToTime;
}

Text& Player::getpCurrentTime(float currentTimerinSeconds)
{
    std::ostringstream s;
    s << (this->totalTime - currentTimerinSeconds);
    sf::String str(s.str());
    this->text.setString(str);
    return this->text;
}

Text& Player::getStatsAsText(void)
{
    return this->playerStats.getText();
}

void Player::resetPlayerStats(void)
{
    this->playerStats.resetStats();
}

Stats& Player::getStats(void)
{
    return this->playerStats;
}


