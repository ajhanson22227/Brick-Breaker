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

void Ball::update(){
    position.x += xSpeed;
    position.y += ySpeed;

    ball.setPosition(position);
}

void Ball::draw(sf::RenderTarget &window){
    window.draw(ball);
}

sf::FloatRect Ball::getPosition(){
    return ball.getGlobalBounds();
}

void Ball::hitPaddle(){
    ySpeed *= -1;
}

void Ball::hitSide(){
    xSpeed *= -1;
}

void Ball::hitTop(){
    ySpeed *= -1;
}