
#pragma once
#include <SFML/Graphics.hpp>
class Paddle  
{
	private:
		sf::RectangleShape paddle;

	public:

		Paddle(sf::Vector2f paddleSize);
		Paddle();
		~Paddle();

		void moveLeft();
		void moveRight();
		void draw(sf::RenderTarget &window);
		//void update();

};