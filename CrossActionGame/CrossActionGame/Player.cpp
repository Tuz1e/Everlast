#include "pch.h"
#include "Player.h"

//TODO: Fix flipping.
// Make player flip towards mouse

Player::Player()
{
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

void Player::Initialize()
{
	myIdleCounter = 0;
	myHealth = 150;
	mySpeed = sf::Vector2f(2.5f, 2.5f);
	myPosition = sf::Vector2f(100.0f, 100.0f);
	myActionState = ActionState::IDLE;
	myPressFlag = false;
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
		Attacking(aDeltaTime);
		break;
	case ActionState::WALK:
		myPosition += myVelocity * aDeltaTime;

		if (myVelocity == sf::Vector2f(0, 0))
		{
			myActionState = ActionState::IDLE;
			SetActionState(4.5f);
		}
		Attacking(aDeltaTime);
		break;
	case ActionState::ATTACK:
		if (myAttackAnimationLength <= 0) 
		{
			std::cout << "\n\n" << "ATTACK" << std::endl;
			myActionState = ActionState::IDLE;
			SetActionState(4.5f);
			myAttackAnimationLength = 0;
		}
		myAttackAnimationLength--;
		break;
	}

	mySprite.UpdateAnimation(aDeltaTime, myPosition, true);
}

void Player::Render(sf::RenderWindow & aWindow)
{
	mySprite.Flip((sf::Mouse::getPosition(aWindow).x < (int)mySprite.GetSprite().getPosition().x) ? FlipSides::LEFT : FlipSides::RIGHT);
	mySprite.Render(aWindow);
}

void Player::Attacking(float &aDeltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!myPressFlag) 
		{
			myPressFlag = true;
			myActionState = ActionState::ATTACK;
			SetActionState(6.5f);

			//Literally no idea why adding 1.25f works, but it works, sooo... just gonna leave it there
			myAttackAnimationLength = mySpriteSheets[ATTACK]->myColumns * 6.5f * aDeltaTime * 1.25f;
		}
	}
	else 
	{
		myPressFlag = false;
	}
}