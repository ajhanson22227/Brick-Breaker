
#pragma once
#include "SFML/Graphics.hpp"

class Brick  
{
	private:
		sf::RectangleShape brick;
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

};