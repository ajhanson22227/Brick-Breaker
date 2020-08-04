
#pragma once
#include <SFML/Graphics.hpp>

class Ball  
{
	private:
		sf::RectangleShape ball;
		sf::Vector2f position;
		float speed = 10.0;

	public:

		Ball(sf::Vector2f ballSize, float xPos, float yPos);
		Ball();
		~Ball();

		void update();
		void draw(sf::RenderTarget &window);

};