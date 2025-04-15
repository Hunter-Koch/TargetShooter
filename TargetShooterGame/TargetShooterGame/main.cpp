#include <SFML/Graphics.hpp>
#include "Target.hpp"
#include "miscFunctions.hpp"
#include "Timer.hpp"

int main()
{
    //this is a test comment. delete me later
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Target t(sf::Vector2f(randRange(0, 1000), randRange(0, 500)), sf::Color::Cyan);//constructing a vector, can construct variables just to be used as a parameter

    Timer time;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();


            if (event->is < sf::Event::MouseButtonPressed>())
            {
                // transform the mouse position from window coordinates to world coordinates
                sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                // retrieve the bounding box of the sprite

                sf::FloatRect bounds = t.getGlobalBounds();

                // hit test
                if (bounds.contains(mouse))
                {
                    t.setPosition(sf::Vector2f(randRange(0, 1000), randRange(0, 500)));
                    if (t.getRadius() == 5)
                    {
                        t.setRadius(100);
                        time.stop();
                    }
                    else                        
                    {    
                        t.setRadius(t.getRadius() - 5);
                        t.playDestroyEffect();
                    }
                }
            }
        }

        window.clear();
        window.draw(t);
        time.setTextStringFromFloat(time.getElapsedTime().asSeconds());
        window.draw(time.getText());
        window.display();
    }
}