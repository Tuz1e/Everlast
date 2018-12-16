#include "pch.h"
#include "SkeletonWarrior.h"
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
	myPosition = sf::Vector2f(800.0f, 550.0f);
	myRecogDistance = 500.0f;
	myHitDistance = 50.0f;
	myActionState = ActionState::IDLE;
	myTargetAcquired = false;
	myAttackingFlag = false;
	myDamage = 2;
	myWeaponRange = 80.0f;
}

void SkeletonWarrior::LoadContent(TextureContainer & aTxtrContainer)
{
	SetSpriteSheet(SKELETON_IDLE, IDLE, &aTxtrContainer); //Sets the idle animation
	SetSpriteSheet(SKELETON_WALK, WALK, &aTxtrContainer); //Sets the walking animation
	SetSpriteSheet(SKELETON_ATTACK, ATTACK, &aTxtrContainer); //Sets the attack animation

	mySprite.Flip(RIGHT);

	SetActionState(4.5f);
	mySprite.SetScale(3.0f, 3.0f);

	myHitbox.setSize
	(
		sf::Vector2f
		(
			mySprite.GetTexture()->getSize().x / mySpriteSheets[myActionState]->myColumns + 25,
			mySprite.GetTexture()->getSize().y / mySpriteSheets[myActionState]->myRows + 25
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

	myWeaponBB.setSize(sf::Vector2f(35, 70));
	myWeaponBB.setTextureRect(sf::IntRect(100, 100, 100, 100));
	myWeaponBB.setOutlineColor(sf::Color::Cyan);
	myWeaponBB.setOutlineThickness(2.0f);
	myWeaponBB.setPosition(sf::Vector2f(myPosition.x + myWeaponRange * ((mySprite.GetFlip() == FlipSides::RIGHT) ? 1 : -0.5), myPosition.y));
	myWeaponBB.setOrigin(
		mySprite.GetTexture()->getSize().x / mySpriteSheets[myActionState]->myColumns,
		mySprite.GetTexture()->getSize().y / mySpriteSheets[myActionState]->myRows / 3.0f - 5.0f);
}

void SkeletonWarrior::Update(float & aDeltaTime, sf::Vector2f &aPosition)
{
	myVelocity.x = aPosition.x - myPosition.x;
	myVelocity.y = aPosition.y - myPosition.y;
	float tempHypo = sqrt((myVelocity.x * myVelocity.x) + (myVelocity.y * myVelocity.y)); //Gets the hypotenuse
	myHitbox.setPosition(myPosition);
	myWeaponBB.setPosition(sf::Vector2f(myPosition.x + myWeaponRange * ((mySprite.GetFlip() == FlipSides::RIGHT) ? 1 : -0.5), myPosition.y));

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
				myAttackingFlag = true;
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
		myAttackingFlag = false;
		if (tempHypo > myHitDistance) 
		{
			myActionState = ActionState::WALK;
			SetActionState(11.0f);
			myAttackingFlag = false;
		}
		break;
	}

	mySprite.UpdateAnimation(aDeltaTime, myPosition, true);
}

void SkeletonWarrior::Render(sf::RenderWindow & aWindow)
{
	mySprite.Flip((myDirection.x < (int)mySprite.GetSprite().getPosition().x) ? FlipSides::LEFT : FlipSides::RIGHT);
	aWindow.draw(myHitbox);
	aWindow.draw(myWeaponBB);
	mySprite.Render(aWindow);
}
