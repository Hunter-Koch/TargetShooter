#include <SFML/Graphics.hpp>
#include "Target.hpp"
#include "miscFunctions.hpp"
#include "Timer.hpp"
#include "healthyTarget.hpp"
#include "gameDirector.hpp"
#include "Player.hpp"


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

    while (window.isOpen())
    {
       director.checkSpawns(time);
       director.runTargetUpdates();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();


            if (event->is < sf::Event::MouseButtonPressed>())
            {
                sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                director.checkClick(window, mouse, p);
            }
        }

        window.clear();
        director.renderTargets(window);
        director.renderCrosshair(window);
        time.setTextStringFromFloat(time.getElapsedTime().asSeconds());
        window.draw(p.getpCurrentTime(time.getElapsedTime().asSeconds()));
        window.display();
    }
}
