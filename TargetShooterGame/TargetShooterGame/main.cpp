#include <SFML/Graphics.hpp>
#include "Target.hpp"
#include "miscFunctions.hpp"
#include "Timer.hpp"
#include "healthyTarget.hpp"
#include "gameDirector.hpp"
#include "Player.hpp"
#include "mainMenu.hpp"


int main()
{
    srand(time(NULL));

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
                   if (bounds.contains(mouse))
                   {
                       mainMenu.setinMenu(false);
                       time.restart();
                       p.resetPlayerStats();
                       director.reset();
                       p.setTotalTime(10.0);
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
       }

        window.clear();
        window.draw(staticBackground);
        if (mainMenu.getinMenu())
        {
            mainMenu.drawMenu(window);
            window.draw(p.getStatsAsText());
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
