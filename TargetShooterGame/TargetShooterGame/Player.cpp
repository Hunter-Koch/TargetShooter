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


