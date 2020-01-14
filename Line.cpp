#include <SFML/Graphics.hpp>
#include <math.h>
#include "Line.h"

Line::Line(sf::Vector2f x1v, sf::Vector2f x2v, int thickness, sf::RenderWindow& win):window(win){
	this->x1 = x1v;
	this->x2 = x2v;
	this->thickness = thickness;
	this->calculateRectangleCoor();
}

Line::~Line(){
	
}

void Line::calculateRectangleCoor(){
	float diffX = this->x2.x - this->x1.x;
	float diffY = this->x2.y - this->x1.y;
	float lenght = sqrtf(powf(diffX,2)+powf(diffY,2)); // distance between two points.
	float angle = atan2f(diffX, diffY) * 180 / M_PI; // angle = atan2(p1.y - p2.y, p1.x - p2.x)
	rectangle.setSize(sf::Vector2f(lenght, thickness*2));
	rectangle.setPosition(sf::Vector2f(this->x1.x,(600 - this->x1.y) - (float)thickness));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setRotation(360 - 90 + angle);
}

void Line::setX1(sf::Vector2f x1){
	this->x1 = x1;
	this->calculateRectangleCoor();
}

void Line::setX2(sf::Vector2f x2){
	this->x2 = x2;
	this->calculateRectangleCoor();
}

void Line::draw(){
	window.draw(rectangle);
}
