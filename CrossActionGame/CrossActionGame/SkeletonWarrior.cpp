#include "pch.h"
#include "SkeletonWarrior.h"
#include "PostNord.h"
#include <cmath>

SkeletonWarrior::SkeletonWarrior()
{
}

SkeletonWarrior::~SkeletonWarrior()
{
}

void SkeletonWarrior::Initialize()
{
	myHealth = 75;
	mySpeed = sf::Vector2f(2.0f, 2.0f);
	myPosition = sf::Vector2f(500.0f, 500.0f);
	myRecogDistance = 500.0f;
	myHitDistance = 50.0f;
	myActionState = ActionState::IDLE;
	myTargetAcquired = false;
	PostNord::Subscribe(this, MessageType::PlayerHit);
}

void SkeletonWarrior::LoadContent(TextureContainer & aTxtrContainer)
{
	SetSpriteSheet(SKELETON_IDLE, IDLE, &aTxtrContainer); //Sets the idle animation
	SetSpriteSheet(SKELETON_WALK, WALK, &aTxtrContainer); //Sets the walking animation
	SetSpriteSheet(SKELETON_ATTACK, ATTACK, &aTxtrContainer); //Sets the attack animation

	SetActionState(4.5f);
	mySprite.SetScale(3.0f, 3.0f);
}

void SkeletonWarrior::Update(float & aDeltaTime, sf::Vector2f &aPosition)
{
	myVelocity.x = aPosition.x - myPosition.x;
	myVelocity.y = aPosition.y - myPosition.y;
	float tempHypo = sqrt((myVelocity.x * myVelocity.x) + (myVelocity.y * myVelocity.y)); //Gets the hypotenuse

	switch (myActionState)
	{
	case IDLE:
		if (tempHypo <= myRecogDistance)
		{
			myTargetAcquired = true;
			myActionState = ActionState::WALK;
			SetActionState(11.0f);
		}
		break;
	case WALK:
		if (tempHypo != 0)
		{
			if (tempHypo <= myHitDistance)
			{
				myActionState = ActionState::ATTACK;
				SetActionState(5.5f);
			}
			else
			{
				myPosition.y += aDeltaTime * mySpeed.y * (myVelocity.y / tempHypo);
				myPosition.x += aDeltaTime * mySpeed.x * (myVelocity.x / tempHypo);
			}
			myDirection = aPosition;
		}
		break;
	case ATTACK:
		if (tempHypo > myHitDistance) 
		{
			myActionState = ActionState::WALK;
			SetActionState(11.0f);
		}
		break;
	}

	mySprite.UpdateAnimation(aDeltaTime, myPosition, true);
}

void SkeletonWarrior::Render(sf::RenderWindow & aWindow)
{
	mySprite.Flip((myDirection.x < (int)mySprite.GetSprite().getPosition().x) ? FlipSides::LEFT : FlipSides::RIGHT);
	mySprite.Render(aWindow);
}

void SkeletonWarrior::ReceiveMessage(const Memorandum &aMemorandum, const MessageType & aMessage)
{
}
