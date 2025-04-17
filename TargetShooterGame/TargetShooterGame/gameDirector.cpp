#include "gameDirector.hpp"
#include "SFML/System.hpp"


GameDirector::GameDirector()
{
	this->timeAtNextSpawn = 1;
}

void GameDirector::checkSpawns(Timer& timer)
{
	int i = 0;

	if (timer.getElapsedTime().asSeconds() >= this->timeAtNextSpawn && this->isAllTargetsSpawned() == false)
	{
		//find random target in array to spawn
		do
		{
			i = randRange(1, 14);
		}while(this->Tarray[i].getIsDestroyed() == false);
		
		//make object appear, spawn object
		this->Tarray[i].appear();

		//setting next time to spawn
		this->timeAtNextSpawn += randRange(1, 2);
	}
}

void GameDirector::checkClick(sf::RenderWindow& thisWindow, sf::Vector2f& mouse)
{
	sf::FloatRect bounds = this->Tarray[0].getGlobalBounds();
		
    // hit test
	for (int i = 1; !bounds.contains(mouse) && i < 15; i++)
    {
		if (!this->Tarray[i].getIsDestroyed())
		{
			bounds = this->Tarray[i].getGlobalBounds();

			if (bounds.contains(mouse))
			{
				this->Tarray[i].destroy();
			}
		}
    }
}

void GameDirector::renderTargets(sf::RenderWindow& thisWindow)
{
	//goes through array, if target isn't destoryed, then render to screen
	for (int i = 0; i < 15; i++)
	{
		if (!this->Tarray[i].getIsDestroyed())
		{
			thisWindow.draw(this->Tarray[i]);
		}
	}
}

void GameDirector::renderCrosshair(sf::RenderWindow& thisWindow)
{
	//sf::Cursor cur(sf::Cursor::Type::Wait);
	//thisWindow.setMouseCursor(cur);


	sf::Texture crosshairTexture;
	crosshairTexture.loadFromFile("Assets/Crosshair/Crosshair_64x64.png", true);
	sf::Sprite crosshair(crosshairTexture);


	sf::Vector2i mouse = sf::Mouse::getPosition(thisWindow);

	crosshair.setPosition(sf::Vector2f(mouse.x -32, mouse.y -32));
	thisWindow.setMouseCursorVisible(false);
	thisWindow.draw(crosshair);
}

bool GameDirector::isAllTargetsDestroyed(void)
{
	for (int i = 0; i < 15; i++)
	{
		if (this->Tarray[i].getIsDestroyed() == false)
		{
			return false;
		}
	}
	return true;
}

bool GameDirector::isAllTargetsSpawned(void)
{
	for (int i = 1; i < 15; i++)//do i = 0 when figure out why 0 cant work
	{
		if (this->Tarray[i].getIsDestroyed() == true)
		{
			return false;
		}
	}
	return true;
}

//to do: figure out why index 0 cant be destroyed