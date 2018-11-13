#include "pch.h"
#include "Player.h"

Player::Player()
{
	mySpeed = sf::Vector2f(3.0f, 3.0f);
	myPosition = sf::Vector2f(10.0f, 10.0f);
	myAnimateFlag = false;
}

Player::~Player()
{
}

void Player::LoadContent(sf::Texture *aTexture)
{
	mySprite.SetTexture(aTexture);
	mySprite.SetAnimation(1, 7, 7, 9.0f);
	mySprite.SetScale(3.0f, 3.0f);

	std::cout << "Loaded Player Content" << std::endl;
}

void Player::Update(float & aDeltaTime)
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
		mySprite.Flip(FlipSides::LEFT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myPosition.x += mySpeed.x * aDeltaTime;
		mySprite.Flip(FlipSides::RIGHT);
	}

	myAnimateFlag = (myPosition != mySprite.GetSprite().getPosition()) ? true : false;

	mySprite.UpdateAnimation(aDeltaTime, myPosition, myAnimateFlag);
}

void Player::Render(sf::RenderWindow & aWindow)
{
	mySprite.Render(aWindow);
}