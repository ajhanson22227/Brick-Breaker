
#pragma once
#include "SFML/Graphics.hpp"

class Brick  
{
	private:
		sf::RectangleShape brick;

	public:

		Brick();
		Brick(float width, float height);
		~Brick();

		void breakBrick();
		void update();
		void draw(sf::RenderTarget &window);

};