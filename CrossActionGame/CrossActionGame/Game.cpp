#include "pch.h"
#include "Game.h"
#include "MathFunc.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Initialize()
{
	myCircle.setRadius(100.0f);
	myCircle.setFillColor(sf::Color::Green);
	myPosition = myCircle.getPosition();
	myVelocity = sf::Vector2f(10.0f, 10.0f);
}

void Game::LoadContent()
{
	mySprite.LoadFromFile("slime-orange.png");
	mySprite.SetScale(20.0f, 20.0f);
}

void Game::Update(const float &aDeltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myPosition.y -= (myVelocity.y * aDeltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myPosition.y += myVelocity.y * aDeltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myPosition.x -= myVelocity.x * aDeltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myPosition.x += myVelocity.x * aDeltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		myCircle.setRadius(myCircle.getRadius() + (1 * aDeltaTime));
		std::cout << "Increasing Size" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		myCircle.setRadius(myCircle.getRadius() - (1 * aDeltaTime));
		std::cout << "Decreasing Size" << std::endl;
	}

	myCircle.setPosition(myPosition);
}

void Game::Render(sf::RenderWindow &aWindow)
{
	aWindow.draw(myCircle);
	mySprite.Render(aWindow);
}