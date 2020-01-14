#ifndef LINE_H
#define LINE_H

class Line
{
private:
	sf::RectangleShape rectangle;
	sf::RenderWindow& window;
	sf::Vector2f x1; 
	sf::Vector2f x2;
	int thickness;
	void calculateRectangleCoor();
	
public:
	Line(sf::Vector2f x1, sf::Vector2f x2, int thickness, sf::RenderWindow& win);
	~Line();
	void setX1(sf::Vector2f x1);
	void setX2(sf::Vector2f x2);
	void draw();
	void update();
};

#endif // LINE_H
