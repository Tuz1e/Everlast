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
	//myAnimateFlag = false;
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

	mySprite.SetTexture(mySpriteSheets[PLAYER_RUN]->myTexture);
	mySprite.SetAnimation(mySpriteSheets[PLAYER_RUN]->myRows, mySpriteSheets[PLAYER_RUN]->myColumns, mySpriteSheets[PLAYER_RUN]->myFrames, myAnimationSpeed);
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
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myVelocity.x = (mySpeed.x * aDeltaTime);
	}

	//if (myVelocity == sf::Vector2f(0, 0) && !myIdleFlag)
	//{
	//	mySprite.SetTexture(mySpriteSheets[PLAYER_IDLE]);
	//	mySprite.SetAnimation(1, 13, 13, myAnimationSpeed);
	//	myIdleFlag = true;
	//}
	//else if (myVelocity != sf::Vector2f(0, 0) && myIdleFlag)
	//{
	//	mySprite.SetTexture(mySpriteSheets[PLAYER_RUN]);
	//	mySprite.SetAnimation(1, 8, 8, myAnimationSpeed);
	//	myIdleFlag = false;
	//	myIdleCounter = 0;
	//}

	//if (myVelocity == sf::Vector2f(0, 0))
	//{
	//	mySprite.SetTexture(mySpriteSheets[PLAYER_IDLE]);
	//	mySprite.SetAnimation(1, 13, 13, myAnimationSpeed);
	//}
	//else
	//{
	//	mySprite.SetTexture(mySpriteSheets[PLAYER_RUN]);
	//	mySprite.SetAnimation(1, 8, 8, myAnimationSpeed);
	//}
	myPosition += myVelocity;
	mySprite.UpdateAnimation(aDeltaTime, myPosition, (myVelocity != sf::Vector2f(0, 0)) ? true : false);
}

void Player::Render(sf::RenderWindow & aWindow)
{
	mySprite.Flip((sf::Mouse::getPosition(aWindow).x < (int)mySprite.GetSprite().getPosition().x) ? FlipSides::LEFT : FlipSides::RIGHT);
	mySprite.Render(aWindow);
}