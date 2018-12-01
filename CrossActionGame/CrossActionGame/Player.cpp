#include "pch.h"
#include "Player.h"

//TODO: Fix flipping. 
// Make player flip towards mouse

Player::Player()
{
	myIdleCounter = 0;
	myAnimationSpeed = 9.0f;
	mySpeed = sf::Vector2f(2.5f, 2.5f);
	myPosition = sf::Vector2f(10.0f, 10.0f);
	myIdleFlag = true;
}

Player::~Player()
{
}

void Player::LoadContent(TextureContainer *aTxtrContainer)
{
	mySpriteSheets[PLAYER_IDLE] = aTxtrContainer->GetTexture(PLAYER_IDLE);
	mySpriteSheets[PLAYER_RUN] = aTxtrContainer->GetTexture(PLAYER_RUN);

	mySprite.SetTexture(mySpriteSheets[PLAYER_IDLE]);
	mySprite.SetAnimation(1, 13, 13, myAnimationSpeed);
	mySprite.SetScale(3.0f, 3.0f);

	printf("\nLoaded player content.");
}

void Player::Update(float & aDeltaTime)
{
	myVelocity = sf::Vector2f(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myVelocity.y = -(mySpeed.y * aDeltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myVelocity.y = (mySpeed.y * aDeltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myVelocity.x = -(mySpeed.x * aDeltaTime);
		//mySprite.Flip(FlipSides::LEFT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myVelocity.x = (mySpeed.x * aDeltaTime);
		//mySprite.Flip(FlipSides::RIGHT);
	}

	if (myVelocity == sf::Vector2f(0, 0) && !myIdleFlag)
	{
			mySprite.SetTexture(mySpriteSheets[PLAYER_IDLE]);
			mySprite.SetAnimation(1, 13, 13, myAnimationSpeed);
			myIdleFlag = true;
	}
	else if (myVelocity != sf::Vector2f(0, 0) && myIdleFlag) 
	{
		mySprite.SetTexture(mySpriteSheets[PLAYER_RUN]);
		mySprite.SetAnimation(1, 8, 8, myAnimationSpeed);
		myIdleFlag = false;
		myIdleCounter = 0;
	}

	myPosition += myVelocity;
	mySprite.UpdateAnimation(aDeltaTime, myPosition, true);
}

void Player::Render(sf::RenderWindow & aWindow)
{
	mySprite.Flip((sf::Mouse::getPosition(aWindow).x < (int)mySprite.GetSprite().getPosition().x) ? FlipSides::LEFT : FlipSides::RIGHT);
	mySprite.Render(aWindow);
}
