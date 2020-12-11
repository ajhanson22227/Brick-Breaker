#include "Brick.h"

Brick::Brick() {}

Brick::Brick(float width, float height, float x, float y)
{
    brick.setSize({width, height});
    brick.setFillColor(getColor(lives));
    brick.setPosition({x, y});
}

Brick::~Brick() {}

sf::Color Brick::getColor(int lives)
{
    if (lives == 3)
    {
        return sf::Color::Blue;
    }
    else if (lives == 2)
    {
        return sf::Color::Green;
    }
    else
    {
        return sf::Color::White;
    }
}

void Brick::draw(sf::RenderTarget &window)
{
    if (!broken)
        window.draw(brick);
}

sf::FloatRect Brick::getPosition()
{
    return brick.getGlobalBounds();
}

float Brick::getWidth()
{
    return brick.getSize().x;
}

float Brick::getHeight()
{
    return brick.getSize().y;
}

void Brick::breakBrick()
{
    lives -= 1;
    if (lives == 0)
        broken = true;
    brick.setFillColor(getColor(lives));
}

float Brick::getXPos()
{
    return brick.getPosition().x;
}

float Brick::getYPos()
{
    return brick.getPosition().y;
}

int Brick::isBroken()
{
    return broken;
}

int Brick::getlife()
{
    return lives;
}