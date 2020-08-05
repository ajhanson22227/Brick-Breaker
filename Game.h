#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"

class Game  
{
	private:
		sf::RenderWindow window;
		Paddle paddle;
		Ball ball;
		
		Brick brick;

	public:

		Game(sf::VideoMode videoMode, float padWidth, float padHeight, float ballSide, float brickWidth, float brickHeight);
		~Game();

		void run();
		void handleEvents();
		void update();
		void draw();

};