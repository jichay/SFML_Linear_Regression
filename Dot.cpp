#include <SFML/Graphics.hpp>
#include "Dot.h"

Dot::Dot(float radius, sf::RenderWindow& win):window(win){
	shape.setRadius(radius);
	shape.setFillColor(sf::Color::Green);
}

Dot::~Dot(){
}

sf::Vector2f Dot::getPos(){
	return shape.getPosition();
}

sf::Vector2f Dot::getPosAsData(){
	sf::Vector2f ret = getPos();
	sf::Vector2u win = window.getSize();
	ret.x = ret.x + shape.getRadius();
	ret.y = win.x - ret.y - shape.getRadius();
	return ret;
}

void Dot::setPos(sf::Vector2f pos){
	shape.setPosition(pos);
}

void Dot::setPos(float x, float y){
	shape.setPosition(x, y);
}

void Dot::draw(){
	window.draw(shape);
}