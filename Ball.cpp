#include "Ball.h"  

Ball::Ball(){

}

Ball::Ball(sf::Vector2f ballSize, float xPos, float yPos){
    ball.setSize(ballSize);

    startXPos = position.x = xPos;
    startYPos = position.y = yPos;
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

void Ball::hitPaddle(sf::FloatRect paddle, float width){
    sf::Vector2f center(this->getHeight() / 2, this->getHeight() /2);
    if (this->getPosition().left - this->getHeight() / 2 > paddle.left + width / 2 ){
        xSpeed = DirRight;
    }
    else{
        xSpeed = DirLeft;
    }
    
    ySpeed = DirUp;


}

void Ball::hitSide(){
    xSpeed *= -1;
}

void Ball::hitTop(){
    ySpeed *= -1;
}

void Ball::hitBottom(){
    position.x = startXPos;
    position.y = startYPos;
    xSpeed = DirRight;
    ySpeed = DirUp;

}

float Ball::getHeight(){
    return ball.getSize().y;
}

float Ball::getXPos(){
    return ball.getPosition().x;
}

float Ball::getYPos(){
    return ball.getPosition().y;
}