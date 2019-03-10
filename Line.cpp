#include <SFML/Graphics.hpp>
#include <math.h>
#include "Line.h"

Line::Line(sf::Vector2f x1, sf::Vector2f x2, int thickness, sf::RenderWindow& win):window(win){
	float diffX = x2.x - x1.x;
	float diffY = x2.y - x1.y;
	float lenght = sqrtf(powf(diffX,2)+powf(diffY,2)); // distance between two points.
	float angle = atan2f(diffX, diffY) * 180 / M_PI; // angle = atan2(p1.y - p2.y, p1.x - p2.x)
	rectangle.setSize(sf::Vector2f(lenght, thickness*2));
	rectangle.setPosition(sf::Vector2f(x1.x, x1.y - (float)thickness));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.rotate(angle); 
}

Line::~Line(){
	
}

void Line::draw(){
	window.draw(rectangle);
}
