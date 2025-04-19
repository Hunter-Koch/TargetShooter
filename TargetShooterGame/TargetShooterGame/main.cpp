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

    Player p;
    Timer time;
    GameDirector director;
    MainMenu mainMenu;

    sf::Texture backgroundTexture("Assets\\background\\Background_sprite.png");
    sf::Sprite staticBackground(backgroundTexture);
    staticBackground.setScale(sf::Vector2f(4, 4));

    //texture and sprite for static background
    sf::Texture backgroundTexture("Assets\\background\\Background_sprite.png");
    sf::Sprite staticBackground(backgroundTexture);
    staticBackground.setScale(sf::Vector2f(4, 4));


    while (window.isOpen())
    {
        if (p.getTotalTime() - time.getElapsedTime().asSeconds() <= 0)
        {
            mainMenu.setinMenu(true);
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
