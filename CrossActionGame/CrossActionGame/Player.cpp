#include "pch.h"
#include "Player.h"

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
	myWeaponRange = 60.0f;
	myAttackingFlag = false;
	myPickupFlag = false;
	myDamage = 25;
}

void Player::LoadContent(TextureContainer &aTxtrContainer)
{
	SetSpriteSheet(PLAYER_IDLE, ActionState::IDLE, &aTxtrContainer);
	SetSpriteSheet(PLAYER_WALK, ActionState::WALK, &aTxtrContainer);
	SetSpriteSheet(PLAYER_ATTACK, ActionState::ATTACK, &aTxtrContainer);
	SetActionState(4.5f);
	mySprite.SetScale(3.0f, 3.0f);
	mySprite.Flip(RIGHT);

	myHitbox.setSize
	(
		sf::Vector2f
		(
			mySprite.GetTexture()->getSize().x / mySpriteSheets[myActionState]->myColumns + 25,
			mySprite.GetTexture()->getSize().y / mySpriteSheets[myActionState]->myRows - 10
		)
	);
	myHitbox.setTextureRect
	(
		sf::IntRect
		(
			mySprite.GetSprite().getGlobalBounds().left,
			mySprite.GetSprite().getGlobalBounds().top,
			mySprite.GetSprite().getGlobalBounds().width,
			mySprite.GetSprite().getGlobalBounds().height / mySpriteSheets[myActionState]->myRows
		)
	);
	myHitbox.setOutlineColor(sf::Color::Magenta);
	myHitbox.setOutlineThickness(2.0f);
	myHitbox.setPosition(myPosition);
	myHitbox.setOrigin(
		mySprite.GetTexture()->getSize().x / mySpriteSheets[myActionState]->myColumns,
		mySprite.GetTexture()->getSize().y / mySpriteSheets[myActionState]->myRows / 3.0f - 5.0f);


	myWeaponBB.setSize(sf::Vector2f(25, 15));
	myWeaponBB.setTextureRect(sf::IntRect(100, 100, 100, 100));
	myWeaponBB.setOutlineColor(sf::Color::Cyan);
	myWeaponBB.setOutlineThickness(2.0f);
	myWeaponBB.setPosition(sf::Vector2f(myPosition.x + myWeaponRange * ((mySprite.GetFlip() == FlipSides::RIGHT) ? 1 : -0.5), myPosition.y));
	myWeaponBB.setOrigin(
		mySprite.GetTexture()->getSize().x / mySpriteSheets[myActionState]->myColumns,
		mySprite.GetTexture()->getSize().y / mySpriteSheets[myActionState]->myRows / 3.0f - 5.0f);

	printf("\nLoaded player content.");
}

void Player::Update(float & aDeltaTime)
{
	myVelocity = sf::Vector2f(0, 0);
	myHitbox.setPosition(myPosition);
	myWeaponBB.setPosition(sf::Vector2f(myPosition.x + myWeaponRange * ((mySprite.GetFlip() == FlipSides::RIGHT) ? 1 : -0.5), myPosition.y));
	
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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) 
	{
		myPickupFlag = true;
	}
	else
	{
		myPickupFlag = false;
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
		myAttackingFlag = false;
		if (myAttackAnimationLength <= 0)
		{
			std::cout << "\n\n" << "ATTACK" << std::endl;
			myActionState = ActionState::IDLE;
			SetActionState(4.5f);
			myAttackAnimationLength = 0;
		}
		else 
		{
			myAttackAnimationLength--;
		}
		break;
	}

	mySprite.UpdateAnimation(aDeltaTime, myPosition, true);
}

void Player::Render(sf::RenderWindow & aWindow)
{
	mySprite.Flip((sf::Mouse::getPosition(aWindow).x < (int)mySprite.GetSprite().getPosition().x) ? FlipSides::LEFT : FlipSides::RIGHT);
	aWindow.draw(myHitbox);
	aWindow.draw(myWeaponBB);
	mySprite.Render(aWindow);
}

//void Player::ReceiveMessage(Memorandum *aMemorandum, const MessageType & aMessage)
//{
//	std::cout << "Received a message in player.";
//}

void Player::Attacking(float &aDeltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!myPressFlag)
		{
			myPressFlag = true;
			myAttackingFlag = true;
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

sf::Vector2f Player::GetVelocity()
{
	return myVelocity;
}

bool Player::GetPickupFlag()
{
	return myPickupFlag;
}
