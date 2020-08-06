#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"

#include <vector>

class Game  
{
	private:
		sf::RenderWindow window;
		Paddle paddle;
		Ball ball;
		//Brick brick;

		std::vector<Brick> bricks;



	public:

		Game(sf::VideoMode videoMode, float padWidth, float padHeight, float ballSide, float brickWidth, float brickHeight);
		~Game();

		void run();
		void handleEvents();
		void update();
		void draw();
		void getBricks(float brickWidth, float brickHeight);

};