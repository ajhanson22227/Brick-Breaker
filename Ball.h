
#pragma once
#include <SFML/Graphics.hpp>

const int DirUp = -10;
const int DirDown = 10;
const int DirLeft = -10;
const int DirRight = 10;

class Ball  
{
	private:
		sf::RectangleShape ball;
		sf::Vector2f position;
		float xSpeed = 10.0;
		float ySpeed = -10.0;
		float startXPos;
		float startYPos;

	public:

		Ball(sf::Vector2f ballSize, float xPos, float yPos);
		Ball();
		~Ball();

		void update();
		void draw(sf::RenderTarget &window);

		sf::FloatRect getPosition();
		void hitPaddle(sf::FloatRect paddle, float width);
		void hitSide();
		void hitTop();
		void hitBottom();
		float getHeight();

		float getXPos();
		float getYPos();

};