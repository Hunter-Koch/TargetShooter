/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 20, 2025
* Description: A header file for target, this will be used as the base
* class for many target variants. This gives the template for target
* including appear, destroy, and update member functions.
*****************************************************************/

#ifndef TARGET
#define TARGET

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "GameObject.hpp"
#include "Timer.hpp"


//all objects have to be transformable and drawable to be rendered
class Target : public sf::CircleShape, public GameObject
{
public:
	/*
	* Function: Target() : sound(destroyEffect), sf::CircleShape(100)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Default Constructor for class Target.
	* Input parameters: void
	* Returns: N/A
	* Preconditions: Target object has to be created.
	* Postconditions: Initalizes data members and loads proper files.
	*/
	Target() : sound(destroyEffect), sf::CircleShape(100)
	{
		this->setPosition(sf::Vector2f(0,1000));
		this->mScoreAwarded = 1;
		this->destroyEffect.loadFromFile("Assets\\sounds\\destroy.mp3");
		this->appearEffect.loadFromFile("Assets\\sounds\\appear.mp3");
		this->texture.loadFromFile("Assets\\targets\\Target_64x64.png");
		this->warningEffect.loadFromFile("Assets\\sounds\\warning.mp3");
		this->setTexture(&texture, true);
		this->sound.setVolume(50);//ranges from 0-100
		this->isDestroyed = true;
		this->timeAlive = 3;
		this->targetTimer.stop();
	}
	
	/*
	* Function: 	Target(sf::Vector2f pos, const sf::Color& color) :
		sf::CircleShape(100), sound(destroyEffect)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Paranmeter constructr for class Target.
	* Input parameters: sf::Vector2f pos, const sf::Color& color
	* Returns: N/A
	* Preconditions: sf::Vector2f pos must represent a coordinate, sf::Color& color must be a properly formatted color.
	* Postconditions: Initalizes data members and loads proper files.
	*/
	Target(sf::Vector2f pos, const sf::Color& color) :
		sf::CircleShape(100), sound(destroyEffect)
	{
		//this->setFillColor(color); //changes color of texture
		this->setPosition(pos);

		this->texture.loadFromFile("Assets\\targets\\Target_64x64.png");
		this->setTexture(&texture, true);

		this->destroyEffect.loadFromFile("Assets\\sounds\\destroy.mp3");
		this->appearEffect.loadFromFile("Assets\\sounds\\appear.mp3");
		this->warningEffect.loadFromFile("Assets\\sounds\\warning.mp3");

		this->sound.setVolume(50);//ranges from 0-100
		mScoreAwarded = 1;
		this->isDestroyed = true;
		this->timeAlive = 3;
		this->targetTimer.stop();
	}

	/*
	* Function: int Target::getScoreAwarded(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for mScoreAwarded data member.
	* Input parameters: void
	* Returns: int
	* Preconditions: N/A
	* Postconditions: Returns value of mScoreAwarded data member.
	*/
	int getScoreAwarded(void);

	/*
	* Function: void Target::setScoreAwarded(int newScore)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Setter for mScoreAwarded data member.
	* Input parameters: int newScore
	* Returns: void
	* Preconditions: int newScore must be any integer, negative scores are allowed.
	* Postconditions: mScoreAwarded is modified to int newScore's value.
	*/
	void setScoreAwarded(int newScore);

	/*
	* Function: void Target::playDestroyEffect(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Plays the destroyEffect data member.
	* Input parameters: void
	* Returns: void
	* Preconditions: destroyEffect must be loaded form file.
	* Postconditions: Plays effect in application.
	*/
	void playDestroyEffect(void);

	/*
	* Function: void Target::playAppearEffect(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Plays the appearEffect data member.
	* Input parameters: void
	* Returns: void
	* Preconditions: appearEffect must be loaded form file.
	* Postconditions: Plays effect in application.
	*/
	void playAppearEffect(void);

	/*
	* Function: void Target::playWarningEffect(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Plays the warningEffect data member.
	* Input parameters: void
	* Returns: void
	* Preconditions: warningEffect must be loaded form file.
	* Postconditions: Plays effect in application.
	*/
	void playWarningEffect(void);

	/*
	* Function: bool Target::getIsDestroyed(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for isDestroyed data member.
	* Input parameters: void
	* Returns: bool
	* Preconditions: N/A
	* Postconditions: Returns value of isDestroyed data member.
	*/
	bool getIsDestroyed(void);

	/*
	* Function: void Target::setIsDestryed(bool newbool)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Setter for isDestroyed data member.
	* Input parameters: bool newbool
	* Returns: void
	* Preconditions: bool newbool must represent the current state of the target object.
	* Postconditions: Modifies isDestroyed data member to value of bool newbool.
	*/
	void setIsDestryed(bool newbool);

	/*
	* Function: int Target::getTimeAlive(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for timeAlive data member.
	* Input parameters: void
	* Returns: int
	* Preconditions: N/A 
	* Postconditions: Returns value of timeAlive data member.
	*/
	int getTimeAlive(void);

	/*
	* Function: void Target::setTimeAlive(int newTimeAlive)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Setter for timeAlive data member.
	* Input parameters: int newTimeAlive
	* Returns: void
	* Preconditions: int newTimeAlive must represent how long target is alive for.
	* Postconditions: Modifies timeAlive data member to value of int newTimeAlive.
	*/
	void setTimeAlive(int newTimeAlive);

	/*
	* Function: void Target::restartTimer(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Restarts the timer in targetTimer data member.
	* Input parameters: void
	* Returns: void
	* Preconditions: N/A
	* Postconditions: Restarts sf::Clock in targetTimer data member.
	*/
	void restartTimer(void);

	/*
	* Function: void Target::stopTimer(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Stops the timer in targetTimer data member.
	* Input parameters: void
	* Returns: void
	* Preconditions: N/A
	* Postconditions: Stops sf::Clock in targetTimer data member.
	*/
	void stopTimer(void);

	/*
	* Function: float Target::getTargetTimerInSeconds(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Gets the time a target has been alive by returning the value of their targetTimer in seconds.
	* Input parameters: void 
	* Returns: float
	* Preconditions: N/A
	* Postconditions: Returns the time of targetTimer as a float in seconds.
	*/
	float getTargetTimerInSeconds(void);

	/*
	* Function: void Target::setDestroyEffect(sf::SoundBuffer& newSound)
	* Date Created: 4/20/2025
	* Date Last Modified: 4/20/2025
	* Description: Setter for destroyEffect data member.
	* Input parameters: sf::SoundBuffer& newSound
	* Returns: void 
	* Preconditions: N/A
	* Postconditions: Sets destroyEffect data member to sf::SoundBuffer& newSound.
	*/
	void setDestroyEffect(sf::SoundBuffer& newSound);

	/*
	* Function: void Target::setAppearEffect(sf::SoundBuffer& newSound)
	* Date Created: 4/20/2025
	* Date Last Modified: 4/20/2025
	* Description: Setter for appearEffect data member.
	* Input parameters: sf::SoundBuffer& newSound
	* Returns: void 
	* Preconditions: N/A
 	* Postconditions: Sets appearEffect data member to sf::SoundBuffer& newSound.
	*/
	void setAppearEffect(sf::SoundBuffer& newSound);

	/*
	* Function: void Target::setWarningEffect(sf::SoundBuffer& newSound)
	* Date Created: 4/20/2025
	* Date Last Modified: 4/20/2025
	* Description: Setter for warningEffect data member.
	* Input parameters: sf::SoundBuffer& newSound
	* Returns: void 
	* Preconditions: n/a
 	* Postconditions: Sets warningEffect data member to sf::SoundBuffer& newSound.
	*/
	void setWarningEffect(sf::SoundBuffer& newSound);


	/*
	* Function: void Target::destroy(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Virtual function that should be overrided in target variants for use in gameDirector.hpp. 
	*				Groups operations that should occur when target is destroyed.
	* Input parameters: void
	* Returns: void
	* Preconditions: Data member isDestroyed must be false.
	* Postconditions: Applies operations that should occur when target is destroyed, including stopping targetTimer, 
	*					setting position, playing destroy effect, and setting isDestroyed to true.
	*/
	virtual void destroy(void);

	/*
	* Function: void Target::appear(void)
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Virtual function that should be overrided in target variants for use in gameDirector.hpp. 
	*				Groups operations that should occur when target appears.
	* Input parameters: void 
	* Returns: void
	* Preconditions: Data member isDestroyed must be true.
	* Postconditions: Applies operations that should occur when target appears, including restarting targetTimer, 
	*					setting position, playing appear effect, and setting isDestroyed to false.
	*/
	virtual void appear(void);

	/*
	* Function: sf::Texture& Target::getTexture()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Getter for texture data member.
	* Input parameters: void
	* Returns: sf::Texture&
	* Preconditions: N/A
	* Postconditions: Returns reference to texture data member.
 	*/
	sf::Texture& getTexture();

	/*
	* Function: void Target::update()
	* Date Created: 4/15/2025
	* Date Last Modified: 4/20/2025
	* Description: Virtual function that should be overrided in target variants for use in gameDirector.hpp.
	*				Groups operations that should occur each tick when target is not destroyed.
	* Input parameters: void
	* Returns: void
	* Preconditions: Data member isDestroyed must be false.
	* Postconditions: Applies operations that should occur when target is not destoyed, such as setting postion or moving.
	*/
	virtual void update();

private:
	bool isDestroyed;
	int mScoreAwarded;
	sf::Texture texture;
	sf::SoundBuffer destroyEffect;
	sf::SoundBuffer appearEffect;
	sf::SoundBuffer warningEffect;
	sf::Sound sound;
	int timeAlive;
	Timer targetTimer;
};



#endif // !TARGET

