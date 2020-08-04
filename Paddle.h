
#pragma once
#include <SFML/Graphics.hpp>
class Paddle  
{
	private:
		sf::RectangleShape paddle;
		sf::Vector2f position;
		float moveSpeed = 25.0;

	public:

		Paddle(sf::Vector2f paddleSize, float xPos, float);
		Paddle();
		~Paddle();

		void moveLeft();
		void moveRight();
		void draw(sf::RenderTarget &window);
		void update();

};