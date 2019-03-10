#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "Dot.h"
#include "Line.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML Template", sf::Style::Titlebar | sf::Style::Close, settings);
	int dotRadius = 5;
	std::list<Dot> dat;
	sf::RectangleShape rectangle(sf::Vector2f(300, 3));
	rectangle.setPosition(sf::Vector2f(150, 150));
	rectangle.setFillColor(sf::Color::Blue);
	Line test(sf::Vector2f(50, 50), sf::Vector2f(100, 400), 1, window);
	Line test2(sf::Vector2f(50, 50), sf::Vector2f(400, 100), 1, window);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i position = sf::Mouse::getPosition(window);
                if(position.x <= 600 && position.x > 0 && position.y <= 600 && position.y > 0){
					dat.push_front(Dot(dotRadius, window));
					dat.front().setPos(position.x-dotRadius, position.y-dotRadius);
					sf::Vector2f pos = dat.front().getPosAsData();
                    printf("X = %f Y = %f\n", pos.x, pos.y);
				}
            }
        }
        window.clear(sf::Color(255, 255, 255, 255));
        for (std::list<Dot>::iterator it=dat.begin(); it != dat.end(); ++it){
			it->draw();
		}
		test.draw();
		test2.draw();
        window.display();
    }
    return 0;
}