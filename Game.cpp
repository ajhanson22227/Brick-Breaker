
#include "Game.h"  

Game::Game(sf::VideoMode videoMode){
    window.create(videoMode, "BRICK BREAKER", sf::Style::Default);
    paddle = Paddle(sf::Vector2f(200, 50), 250, 450);
    ball = Ball(sf::Vector2f(50, 50), 250, 300);
}

Game::~Game(){}

void Game::update(){
    paddle.update();
}

void Game::draw(){
    paddle.draw(window);
    ball.draw(window);
}

void Game::run(){
    window.setFramerateLimit(15);

    while (window.isOpen()){
        handleEvents();
        window.clear();
        update();
        draw();
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
            else if (event.key.code == sf::Keyboard::Left){
                paddle.moveLeft();
            }
            else if (event.key.code == sf::Keyboard::Right){
                paddle.moveRight();
            }
        }
    }
}