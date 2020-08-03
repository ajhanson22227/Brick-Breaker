#include "Game.h"  

Game::Game(sf::VideoMode videoMode){
    window.create(videoMode, "BRICK BREAKER", sf::Style::Default);
}

Game::~Game(){}

void Game::run(){
    sf::RectangleShape rect(sf::Vector2f(25, 20));
    rect.setFillColor(sf::Color::Green);

    while (window.isOpen()){
        handleEvents();
        window.clear();
        window.draw(rect);
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