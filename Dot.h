#ifndef DOT_H
#define DOT_H

class Dot
{
private:
	sf::CircleShape shape;
	sf::RenderWindow& window;
public:
	Dot(float radius, sf::RenderWindow& win);
	~Dot();
	sf::Vector2f getPos();
	sf::Vector2f getPosAsData();
	void setPos(sf::Vector2f pos);
	void setPos(float x, float y);
	void draw();
};

#endif // BALL_H
