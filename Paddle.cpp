#include "Paddle.h" 
#include <iostream>

Paddle::Paddle(sf::Vector2f paddleSize, float xPos, float yPos){
    position.x = xPos;
    position.y = yPos;
    paddle.setSize(paddleSize);
    paddle.setPosition(position);
    paddle.setFillColor(sf::Color::White);
}

Paddle::Paddle(){
    paddle.setSize({400, 200});
    paddle.setPosition(sf::Vector2f(250, 450));
    paddle.setFillColor(sf::Color::White);
}
Paddle::~Paddle(){}

void Paddle::update(){
    paddle.setPosition(position);
}

void Paddle::draw(sf::RenderTarget &window){
    window.draw(paddle);
}

void Paddle::moveLeft(){
    position.x -= moveSpeed;
}

void Paddle::moveRight(){
    position.x += moveSpeed;
}

sf::FloatRect Paddle::getPosition(){
    return paddle.getGlobalBounds();
}