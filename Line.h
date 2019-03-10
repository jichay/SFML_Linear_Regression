#ifndef LINE_H
#define LINE_H

class Line
{
private:
	sf::RectangleShape rectangle;
	sf::RenderWindow& window;
public:
	Line(sf::Vector2f x1, sf::Vector2f x2, int thickness, sf::RenderWindow& win);
	~Line();
	void draw();
};

#endif // LINE_H
