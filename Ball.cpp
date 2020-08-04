#include "Ball.h"  

Ball::Ball(){
    
}

Ball::Ball(sf::Vector2f ballSize, float xPos, float yPos){
    ball.setSize(ballSize);

    position.x = xPos;
    position.y = yPos;
    ball.setPosition(position);

    ball.setFillColor(sf::Color::White);
}

Ball::~Ball(){}

void Ball::draw(sf::RenderTarget &window){
    window.draw(ball);
}