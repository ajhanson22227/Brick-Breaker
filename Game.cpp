
#include "Game.h"  

Game::Game(sf::VideoMode videoMode, float padWidth, float padHeight, float ballSide){
    window.create(videoMode, "BRICK BREAKER", sf::Style::Default);
    //sets the paddle position to half the window and to the bottom of the screen
    paddle = Paddle(sf::Vector2f(padWidth, padHeight), videoMode.width / 2 - padWidth, videoMode.height - padHeight - 10);
    //Set ball position to half the winow width and puts it in the air so it doesn't hit the paddle right away
    ball = Ball(sf::Vector2f(ballSide, ballSide), videoMode.width / 2 - ballSide, videoMode.height - 4*ballSide);
}

Game::~Game(){}

void Game::update(){
    //move paddle
    paddle.update();

    //Get ball interactions
    //If the ball hits paddle
    if (ball.getPosition().intersects(paddle.getPosition()))
        ball.hitPaddle();
    //if the ball hits the left/right side
    if (ball.getPosition().left == 0 || ball.getPosition().left + 50 > 800)
        ball.hitSide();
    //if the ball hits the top of screen
    if (ball.getPosition().top == 0)
        ball.hitTop();
    //if the ball hits the bottom of screen
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