/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: A header file for floatingTarget, this will be used as one
* of the many target variants used in the game. It will spawn at
* either the left or right side and float across the screen.
*****************************************************************/

#ifndef FLOATING
#define FLOATING

#include "Target.hpp"

class floatingTarget :public Target
{
public:
    /*
    * Function:	floatingTarget() : Target()
    * Date Created: 4/15/2025
    * Date Last Modified: 4/20/2025
    * Description: Default Constructor for floatingTarget
    * Input parameters: void
    * Returns: N/A
    * Preconditions: floatingTarget object has to be created.
    * Postconditions: Initalizes data members and loads proper files.
    */
	floatingTarget() : Target()
    {
        this->getTexture().loadFromFile("Assets\\targets\\BalloonTarget.png");
        this->setTexture(&getTexture(), true);
        this->setScoreAwarded(1);
        this->setTimeAlive(7);
        sf::SoundBuffer newAppearSound("Assets\\sounds\\BalloonInflate.wav");
        this->setAppearEffect(newAppearSound);
        sf::SoundBuffer newDissapearSound("Assets\\sounds\\BalloonPop.wav");
        this->setDestroyEffect(newDissapearSound);
    }
    
    /*
    * Function: void negativeTarget::destroy()
    * Date Created: 4/15/2025
    * Date Last Modified: 4/20/2025
    * Description: Overloaded destroy function from base target class, Groups operations that should occur when target appears.
    * Input parameters: void
    * Returns: void
    * Preconditions: Data member isDestroyed must be false.
    * Postconditions: Applies operations that should occur when target is destroyed, including stopping targetTimer,
    *					setting position, playing destroy effect, and setting isDestroyed to true.
    */
    void destroy() override;

    /*
    * Function: void floatingTarget::appear()
    * Date Created: 4/15/2025
    * Date Last Modified: 4/20/2025
    * Description: Overloaded appear function from base target class, Groups operations that should occur when target appears.
    * Input parameters: void
    * Returns: void
    * Preconditions: Data member isDestroyed must be true.
    * Postconditions:Applies operations that should occur when target appears, including restarting targetTimer,
    *					setting position, playing appear effect, and setting isDestroyed to false.
    */
    void appear() override;

    /*
    * Function: void floatingTarget::update()
    * Date Created: 4/15/2025
    * Date Last Modified: 4/20/2025
    * Description: Overloaded function for use in gameDirector.hpp. Groups operations that should occur each tick when target is not 
                    destroyed including movement.
    * Input parameters: void
    * Returns: void
    * Preconditions: Data member isDestroyed must be false.
    * Postconditions: Applies operations that should occur when target is not destoyed, such as moving.
    */
    void update() override;

private:
    int direction = 1;
    float x = 0;
    float speed = 0.1f; // Adjust for how fast it moves
    float amplitude = 100.0f; // Curve height
    float frequency = 0.007f; // Curve tightness
    float baseY = 300.0f;
};

#endif