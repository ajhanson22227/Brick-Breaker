
#include "Game.h"  

Game::Game(sf::VideoMode videoMode, float padWidth, float padHeight, float ballSide){
    window.create(videoMode, "BRICK BREAKER", sf::Style::Default);
    paddle = Paddle(sf::Vector2f(padWidth, padHeight), videoMode.width / 2 - padWidth, videoMode.height - padHeight - 10);
    ball = Ball(sf::Vector2f(ballSide, ballSide), videoMode.width / 2 - ballSide, videoMode.height - 4*ballSide);
}

Game::~Game(){}

void Game::update(){
    paddle.update();

    if (ball.getPosition().intersects(paddle.getPosition()))
        ball.hitPaddle();
    if (ball.getPosition().left == 0 || ball.getPosition().left + 50 > 800)
        ball.hitSide();
    if (ball.getPosition().top == 0)
        ball.hitTop();
    if (ball.getPosition().top == window.getSize().y)
        ball.hitBottom();
    ball.update();
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