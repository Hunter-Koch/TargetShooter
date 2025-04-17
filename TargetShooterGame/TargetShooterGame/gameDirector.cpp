#include "gameDirector.hpp"
#include "SFML/System.hpp"


GameDirector::GameDirector()
{
	this->timeAtNextSpawn = 1;
	this->setTarray();
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
		}while(this->Tarray[i]->getIsDestroyed() == false);
		
		//make object appear, spawn object
		this->Tarray[i]->appear();

		//setting next time to spawn
		this->timeAtNextSpawn += randRange(1, 2);
	}
}

void GameDirector::checkClick(sf::RenderWindow& thisWindow, sf::Vector2f& mouse)
{
	sf::FloatRect bounds = this->Tarray[0]->getGlobalBounds();
		
    // hit test
	for (int i = 1; !bounds.contains(mouse) && i < 15; i++)
    {
		if (!this->Tarray[i]->getIsDestroyed())
		{
			bounds = this->Tarray[i]->getGlobalBounds();

			if (bounds.contains(mouse))
			{
				this->Tarray[i]->destroy();
			}
		}
    }
}

void GameDirector::renderTargets(sf::RenderWindow& thisWindow)
{
	//goes through array, if target isn't destoryed, then render to screen
	for (int i = 0; i < 15; i++)
	{
		if (!this->Tarray[i]->getIsDestroyed())
		{
			thisWindow.draw(*this->Tarray[i]);
		}
	}
}

void GameDirector::runTargetUpdates(void)
{
	for (int i = 0; i < 15; i++)
	{
		if (!this->Tarray[i]->getIsDestroyed())
		{
			Tarray[i]->update();
		}
	}
}

bool GameDirector::isAllTargetsDestroyed(void)
{
	for (int i = 0; i < 15; i++)
	{
		if (this->Tarray[i]->getIsDestroyed() == false)
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
		if (this->Tarray[i]->getIsDestroyed() == true)
		{
			return false;
		}
	}
	return true;
}

void GameDirector::setTarray(void)
{
	//choose amount of each target
	this->Tarray[0] = new Target;
	this->Tarray[1] = new floatingTarget;
	this->Tarray[2] = new floatingTarget;
	this->Tarray[3] = new floatingTarget;
	this->Tarray[4] = new duckTarget;
	this->Tarray[5] = new duckTarget;
	this->Tarray[6] = new duckTarget;
	this->Tarray[7] = new duckTarget;
	this->Tarray[8] = new duckTarget;
	this->Tarray[9] = new duckTarget;
	this->Tarray[10] = new floatingTarget;
	this->Tarray[11] = new Target;
	this->Tarray[12] = new Target;
	this->Tarray[13] = new Target;
	this->Tarray[14] = new Target;
}

//to do: figure out why index 0 cant be destroyed