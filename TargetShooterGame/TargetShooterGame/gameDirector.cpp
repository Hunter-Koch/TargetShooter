#include "gameDirector.hpp"
#include "SFML/System.hpp"


GameDirector::GameDirector()
{
	this->timeAtNextSpawn = 1;
}

void GameDirector::checkSpawns(Timer& timer)
{
	if (timer.getElapsedTime().asSeconds() >= this->timeAtNextSpawn)
	{
		int i = randRange(0, 14);

		this->Tarray[i].setIsDestryed(false);
		this->Tarray[i].appear();

		this->timeAtNextSpawn += randRange(1, 3);
	}
}

void GameDirector::checkClick(sf::RenderWindow& thisWindow, sf::Vector2f& mouse)
{
	sf::FloatRect bounds = this->Tarray[0].getGlobalBounds();
		
    // hit test
	for (int i = 0; !bounds.contains(mouse) && i < 15; i++)
    {
		bounds = this->Tarray[i].getGlobalBounds();
		if (bounds.contains(mouse))
		{
			this->Tarray[i].destroy();
		}
    }
}

void GameDirector::renderTargets(sf::RenderWindow& thisWindow)
{
	for (int i = 0; i < 15; i++)
	{
		if (!this->Tarray[i].getIsDestroyed())
		{
			thisWindow.draw(this->Tarray[i]);
		}
	}
}
