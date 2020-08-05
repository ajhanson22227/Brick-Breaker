#include "Brick.h"  

Brick::Brick(){}

Brick::Brick(float width, float height){
    brick.setSize({width, height});
    brick.setFillColor(sf::Color::White);
    brick.setPosition({100,200});
}

Brick::~Brick(){}

void Brick::draw(sf::RenderTarget &window){
    window.draw(brick);
}

