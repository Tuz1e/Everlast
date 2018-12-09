#include "pch.h"
#include "Player.h"

//TODO: Fix flipping.
// Make player flip towards mouse

Player::Player()
{
	myIdleCounter = 0;
	myAnimationSpeed = 11.0f;
	myHealth = 150;
	mySpeed = sf::Vector2f(2.5f, 2.5f);
	myPosition = sf::Vector2f(10.0f, 10.0f);
}

Player::~Player()
{
	mySprite.~SpriteAnim();
	for (Textures* txtrptr : mySpriteSheets)
	{
		PtrDelete(txtrptr->myTexture);
		PtrDelete(txtrptr);
	}
}

void Player::LoadContent(TextureContainer *aTxtrContainer)
{
	SetSpriteSheet(IDLE, PLAYER_IDLE, aTxtrContainer);
	SetSpriteSheet(RUN, PLAYER_RUN, aTxtrContainer);

	mySprite.SetTexture(mySpriteSheets[RUN]->myTexture);
	mySprite.SetScale(3.0f, 3.0f);
	mySprite.SetAnimation(mySpriteSheets[PLAYER_RUN]->myRows, mySpriteSheets[PLAYER_RUN]->myColumns, mySpriteSheets[PLAYER_RUN]->myFrames, myAnimationSpeed);

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
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myVelocity.x = (mySpeed.x * aDeltaTime);
	}

	myPosition += myVelocity;
	mySprite.UpdateAnimation(aDeltaTime, myPosition, (myVelocity != sf::Vector2f(0, 0)) ? true : false);
}

void Player::Render(sf::RenderWindow & aWindow)
{
	mySprite.Flip((sf::Mouse::getPosition(aWindow).x < (int)mySprite.GetSprite().getPosition().x) ? FlipSides::LEFT : FlipSides::RIGHT);
	mySprite.Render(aWindow);
}