#include "pch.h"
#include "Player.h"

Player::Player()
{
	mySpeed = sf::Vector2f(5.0f, 5.0f);
	myPosition = sf::Vector2f(10.0f, 10.0f);
}

Player::~Player()
{
}

void Player::LoadContent()
{
	mySprite.LoadFromFile("gabe-idle-run.png");
	mySprite.SetScale(3.0f, 3.0f);
}

void Player::Update(const float & aDeltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myPosition.y -= (mySpeed.y * aDeltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myPosition.y += mySpeed.y * aDeltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myPosition.x -= mySpeed.x * aDeltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myPosition.x += mySpeed.x * aDeltaTime;
	}

	mySprite.SetPosition(myPosition);
}

void Player::Render(sf::RenderWindow & aWindow)
{
	mySprite.Render(aWindow, false);
}