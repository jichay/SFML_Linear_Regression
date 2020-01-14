#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <math.h> 
#include "Dot.h"
#include "Line.h"

double get_x_avg(std::list<Dot> data){
	double sum = 0;
	std::list<Dot>::iterator it;
	for(it = data.begin(); it != data.end(); it++){
		sum += it->getPosAsData().x;
	}
	return sum / data.size();
}

double get_y_avg(std::list<Dot> data){
	double sum = 0;
	std::list<Dot>::iterator it;
	for(it = data.begin(); it != data.end(); it++){
		sum += it->getPosAsData().y;
	}
	return sum / data.size();
}

double get_m(std::list<Dot> data){
	double numerat = 0;
	double denom = 0;
	std::list<Dot>::iterator it;
	double x_avg = get_x_avg(data);
	double y_avg = get_y_avg(data);
	for(it = data.begin(); it != data.end(); it++){
		double res1 = (it->getPosAsData().x - x_avg);
		double res2 = (it->getPosAsData().y - y_avg);
		numerat += res1*res2;
		denom += (it->getPosAsData().x - x_avg) * (it->getPosAsData().x - x_avg);
	}
	return numerat / denom;
}

double get_b(std::list<Dot> data){
	return get_y_avg(data) - (get_m(data) * get_x_avg(data));
}

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML Template", sf::Style::Titlebar | sf::Style::Close, settings);
	int dotRadius = 5 ;
	std::list<Dot> dat;
	Line line(sf::Vector2f(0, 0), sf::Vector2f(0, 0), 2, window);
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
					
					//sf::Vector2f pos = dat.front().getPosAsData();
					
					double m = get_m(dat);
					double b = get_b(dat);
					
					double x1 = 0;
					double y1 = m * x1 + b;
					
					double x2 = 600;
					double y2 = m * x2 + b;
					
					line.setX1(sf::Vector2f(x1, y1));
					line.setX2(sf::Vector2f(x2, y2));
					
				}
			}
		}
		window.clear(sf::Color(255, 255, 255, 255));//Remove and replace with a system where we know what has been drawn or not to avoid all object redraw
		for (std::list<Dot>::iterator it=dat.begin(); it != dat.end(); ++it){
			it->draw();
		}
		line.draw();
		window.display();
	}
	return 0;
}