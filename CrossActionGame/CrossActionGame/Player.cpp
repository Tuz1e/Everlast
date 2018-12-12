#include "pch.h"
#include "Player.h"

//TODO: Fix flipping.
// Make player flip towards mouse

Player::Player()
{
	myIdleCounter = 0;
	myHealth = 150;
	mySpeed = sf::Vector2f(2.5f, 2.5f);
	myPosition = sf::Vector2f(100.0f, 100.0f);
	myActionState = ActionState::IDLE;
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

void Player::LoadContent(TextureContainer &aTxtrContainer)
{
	SetSpriteSheet(PLAYER_IDLE, ActionState::IDLE, &aTxtrContainer);
	SetSpriteSheet(PLAYER_WALK, ActionState::WALK, &aTxtrContainer);
	SetSpriteSheet(PLAYER_ATTACK, ActionState::ATTACK, &aTxtrContainer);

	SetActionState(4.5f);
	mySprite.SetScale(3.0f, 3.0f);

	printf("\nLoaded player content.");
}

void Player::Update(float & aDeltaTime)
{
	myVelocity = sf::Vector2f(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myVelocity.y = -mySpeed.y;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myVelocity.y = mySpeed.y;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myVelocity.x = -mySpeed.x;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myVelocity.x = mySpeed.x;
	}

	switch (myActionState)
	{
	case ActionState::IDLE:
		if (myVelocity != sf::Vector2f(0, 0))
		{
			myActionState = ActionState::WALK;
			SetActionState(11.0f);
		}
		Attacking();
		break;
	case ActionState::WALK:
		myPosition += myVelocity * aDeltaTime;

		if (myVelocity == sf::Vector2f(0, 0))
		{
			myActionState = ActionState::IDLE;
			SetActionState(4.5f);
		}
		Attacking();
		break;
	case ActionState::ATTACK:
		//myActionState == ActionState::IDLE;
		//SetActionState(4.5f);
		break;
	}

	mySprite.UpdateAnimation(aDeltaTime, myPosition, true);
}

void Player::Render(sf::RenderWindow & aWindow)
{
	mySprite.Flip((sf::Mouse::getPosition(aWindow).x < (int)mySprite.GetSprite().getPosition().x) ? FlipSides::LEFT : FlipSides::RIGHT);
	mySprite.Render(aWindow);
}

void Player::Attacking()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		myActionState = ActionState::ATTACK;
		SetActionState(6.0f);
	}
}