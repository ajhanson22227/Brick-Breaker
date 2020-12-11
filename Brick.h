
#pragma once
#include "SFML/Graphics.hpp"
#include <cstdlib>

class Brick
{
private:
	sf::RectangleShape brick;
	int lives = rand() % 3 + 1;
	bool broken = false;

public:
	Brick();
	Brick(float width, float height, float x, float y);
	~Brick();

	void breakBrick();
	sf::FloatRect getPosition();
	void update();
	void draw(sf::RenderTarget &window);

	float getWidth();
	float getHeight();
	float getXPos();
	float getYPos();

	int getLives();
};