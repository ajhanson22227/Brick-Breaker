#include "Paddle.h" 

Paddle::Paddle(sf::Vector2f paddleSize){
    paddle.setSize(paddleSize);
    paddle.setPosition(sf::Vector2f(250, 450));
    paddle.setFillColor(sf::Color::White);
}

Paddle::Paddle(){
    paddle.setSize({400, 200});
    paddle.setPosition(sf::Vector2f(250, 450));
    paddle.setFillColor(sf::Color::White);
}
Paddle::~Paddle(){}

void Paddle::draw(sf::RenderTarget &window){
    window.draw(paddle);
}