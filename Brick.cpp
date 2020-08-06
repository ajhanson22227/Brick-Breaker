#include "Brick.h"  

Brick::Brick(){}

Brick::Brick(float width, float height, float x, float y){
    brick.setSize({width, height});
    brick.setFillColor(sf::Color::White);
    brick.setPosition({x,y});
}

Brick::~Brick(){}

void Brick::draw(sf::RenderTarget &window){
    if (!broken)
        window.draw(brick);
}

sf::FloatRect Brick::getPosition(){
    return brick.getGlobalBounds();
}

float Brick::getWidth(){
    return brick.getSize().x;
}

float Brick::getHeight(){
    return brick.getSize().y;
}

void Brick::breakBrick(){
    broken = true;
}

float Brick::getXPos(){
    return brick.getPosition().x;
}

float Brick::getYPos(){
    return brick.getPosition().y;
}
