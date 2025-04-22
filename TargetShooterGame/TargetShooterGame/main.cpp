/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: File that will store main(), run most of the
* operations, and take player input. This includes navigating menus, 
* starting the game, and playing the game.
*****************************************************************/

#include <SFML/Graphics.hpp>
#include "Target.hpp"
#include "miscFunctions.hpp"
#include "Timer.hpp"
#include "healthyTarget.hpp"
#include "gameDirector.hpp"
#include "Player.hpp"
#include "mainMenu.hpp"
#include "TestCases.hpp"

int main()
{
    srand(time(NULL));

    runTestCases();

    //this is a test comment. delete me later
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Target Shooter");
    
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Music musicDirector("Assets\\sounds\\music.mp3");
    musicDirector.play();
    musicDirector.setVolume(30);


    Player p;
    Timer time;
    GameDirector director;
    MainMenu mainMenu;

    //set gunshot sounds
    sf::SoundBuffer shotSound("Assets\\sounds\\Gunshot.wav");
    sf::Sound shot(shotSound);
    shot.setVolume(50); 

    sf::Texture backgroundTexture("Assets\\background\\Background_sprite.png");
    sf::Sprite staticBackground(backgroundTexture);
    staticBackground.setScale(sf::Vector2f(4, 4));

    while (window.isOpen())
    {
        
        if (p.getTotalTime() - time.getElapsedTime().asSeconds() <= 0)
        {
            mainMenu.setinMenu(true);
            musicDirector.play();
            time.restart();
        }

        if(!mainMenu.getinMenu())
        {
            director.checkSpawns(time);
            director.runTargetUpdates();
        }


       while (const std::optional event = window.pollEvent())
       {
           if (event->is<sf::Event::Closed>())
               window.close();


           if (event->is < sf::Event::MouseButtonPressed>())
           {
               sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

               if (mainMenu.getinMenu())
               {
                   
                   sf::FloatRect bounds = mainMenu.getButton().getGlobalBounds();
                   sf::FloatRect ruleBBounds = mainMenu.getRuleButton().getGlobalBounds(); 
                   sf::FloatRect backBBounds = mainMenu.getBackButton().getGlobalBounds(); 
                   if (bounds.contains(mouse))
                   {
                       mainMenu.setinMenu(false);
                       time.restart();
                       p.resetPlayerStats();
                       director.reset();
                       p.setTotalTime(10.0);
                   }
                   else if (mainMenu.getInRules() == false && ruleBBounds.contains(mouse))//check if the rules button was pushed
                   {
                       mainMenu.setinRules(true);
                       
                   }

                   else if (mainMenu.getInRules() == true && backBBounds.contains(mouse))
                   {
                       mainMenu.setinRules(false);
                       
                   }
               }
               else
               {
                   //play gunshot sounds
                   shot.setBuffer(shotSound);
                   shot.play();

                    director.checkClick(window, mouse, p);
               }
           }
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
           {
                 
               mainMenu.setinMenu(true);
           }
       }

        window.clear();
        window.draw(staticBackground);
        if (mainMenu.getinMenu())
        {
            if (mainMenu.getInRules())
            {
                mainMenu.drawRules(window);
                
            }
            else {
                mainMenu.drawMenu(window);
                window.draw(p.getStatsAsText());
            }

           
        }
        else
        {
            director.renderTargets(window);
            time.setTextStringFromFloat(time.getElapsedTime().asSeconds());
            window.draw(p.getpCurrentTime(time.getElapsedTime().asSeconds()));
        }
        director.renderCrosshair(window);
        window.display();
    }
}
