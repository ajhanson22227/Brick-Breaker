
#pragma once
#include <SFML/Graphics.hpp>

class Game  
{
	private:
		sf::RenderWindow window;
	public:

		Game(sf::VideoMode videoMode);
		~Game();

		void run();
		void handleEvents();

};