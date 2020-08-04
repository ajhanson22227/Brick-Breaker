
#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"

class Game  
{
	private:
		sf::RenderWindow window;
		Paddle paddle;

	public:

		Game(sf::VideoMode videoMode);
		~Game();

		void run();
		void handleEvents();
		void update();

};