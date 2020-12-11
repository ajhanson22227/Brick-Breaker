
#include "Game.h"
#include <iostream>

Game::Game(sf::VideoMode videoMode, float padWidth, float padHeight, float ballSide, float brickWidth, float brickHeight)
{
    window.create(videoMode, "BRICK BREAKER", sf::Style::Default);
    //sets the paddle position to half the window and to the bottom of the screen
    paddle = Paddle(sf::Vector2f(padWidth, padHeight), videoMode.width / 2 - padWidth, videoMode.height - padHeight - 10);
    //Set ball position to half the winow width and puts it in the air so it doesn't hit the paddle right away
    ball = Ball(sf::Vector2f(ballSide, ballSide), videoMode.width / 2 - ballSide, videoMode.height - 4 * ballSide);

    //brick = Brick(brickWidth, brickHeight);
    getBricks(brickWidth, brickHeight);
}

Game::~Game() {}

void Game::update()
{
    //move paddle
    paddle.update();

    //Get ball interactions
    //If the ball hits paddle
    if (ball.getPosition().intersects(paddle.getPosition()))
        ball.hitPaddle(paddle.getPosition(), paddle.getWidth());
    //if the ball hits the left/right side
    if (ball.getPosition().left == 0 || ball.getPosition().left + 20 > 800)
        ball.hitSide();
    //if the ball hits the top of screen
    if (ball.getPosition().top == 0)
        ball.hitTop();
    //if the ball hits the bottom of screen
    if (ball.getPosition().top == window.getSize().y)
        ball.hitBottom();

    for (int i = 0; i < bricks.size(); i += 1)
    {

        if (ball.getPosition().intersects(bricks[i].getPosition()))
        {
            sf::Vector2f center(ball.getPosition().left + ball.getHeight() / 2, ball.getPosition().top + ball.getHeight() / 2);
            if (bricks[i].getPosition().contains(center.x, ball.getPosition().top) ||
                (bricks[i].getPosition().contains(center.x, ball.getPosition().top + ball.getHeight())))
            {
                //std::cout << "TOP/BOTTOM\n";
                bricks[i].breakBrick();
                if (bricks[i].isBroken())
                {
                    bricks.erase(bricks.begin() + i);
                }

                ball.hitTop();
            }
            else if (bricks[i].getPosition().contains(ball.getPosition().left, center.y) ||
                     (bricks[i].getPosition().contains(ball.getPosition().left + ball.getHeight(), center.y)))
            {
                //std::cout << "side\n";
                bricks[i].breakBrick();
                if (bricks[i].isBroken())
                {
                    bricks.erase(bricks.begin() + i);
                }
                ball.hitSide();
            }
        }
    }

    ball.update();
}

void Game::draw()
{
    paddle.draw(window);
    ball.draw(window);
    for (auto &brick : bricks)
    {
        brick.draw(window);
    }
}

void Game::run()
{
    window.setFramerateLimit(20);

    while (window.isOpen())
    {
        handleEvents();
        window.clear();
        update();
        draw();
        window.display();
    }
}

void Game::handleEvents()
{
    //Checks for events and handles them accordingly
    sf::Event event;
    while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
            else if (event.key.code == sf::Keyboard::Left)
            {
                if (paddle.getPosition().left != 0)
                    paddle.moveLeft();
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                if (paddle.getPosition().left + paddle.getWidth() != window.getSize().x)
                    paddle.moveRight();
            }
        }
    }
}

void Game::getBricks(float brickWidth, float brickHeight)
{
    for (int i = 1; i < window.getSize().x; i += brickWidth + 5)
    {
        for (int j = 0; j < window.getSize().y / 3; j += brickHeight + 5)
        {
            bricks.push_back(Brick(brickWidth, brickHeight, i, j));
        }
    }
}