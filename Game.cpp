
#include "Game.h"  

Game::Game(sf::VideoMode videoMode){
    window.create(videoMode, "BRICK BREAKER", sf::Style::Default);
    paddle = Paddle(sf::Vector2f(200, 50));
}

Game::~Game(){}

void Game::run(){
    

    while (window.isOpen()){
        handleEvents();
        window.clear();
        paddle.draw(window);
        window.display();
    }
}

void Game::handleEvents(){
    //Checks for events and handles them accordingly
    sf::Event event;
    while (window.pollEvent(event)){
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed){
            if (event.key.code == sf::Keyboard::Escape){
                window.close();
            }
        }
    }
}