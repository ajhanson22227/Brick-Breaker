#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"

class Game  
{
	private:
		sf::RenderWindow window;
		Paddle paddle;
		Ball ball;

	public:

		Game(sf::VideoMode videoMode, float padWidth, float padHeight, float ballSide);
		~Game();

		void run();
		void handleEvents();
		void update();
		void draw();

};