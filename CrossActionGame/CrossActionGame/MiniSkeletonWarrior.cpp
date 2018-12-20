#include "pch.h"
#include "MiniSkeletonWarrior.h"

//Also known as mini suicide bombers

MiniSkeletonWarrior::MiniSkeletonWarrior()
{
}


MiniSkeletonWarrior::~MiniSkeletonWarrior()
{
}

void MiniSkeletonWarrior::Initialize()
{
	myHealth = 75;
	mySpeed = sf::Vector2f(2.0f, 2.0f);
	myRecogDistance = 500.0f;
	myHitDistance = 50.0f;
	myActionState = ActionState::IDLE;
	myTargetAcquired = false;
	myAttackingFlag = false;
	myDamage = 30;
	myWeaponRange = 80.0f;
	myAliveFlag = true;
}

void MiniSkeletonWarrior::LoadContent(TextureContainer & aTxtrContainer)
{
	SetSpriteSheet(TextureID::SKELETON_IDLE, ActionState::IDLE, &aTxtrContainer); //Sets the idle animation
	SetSpriteSheet(TextureID::SKELETON_WALK, ActionState::WALK, &aTxtrContainer); //Sets the walking animation
	SetSpriteSheet(TextureID::SKELETON_ATTACK, ActionState::ATTACK, &aTxtrContainer); //Sets the attack animation

	mySprite.Flip(RIGHT);

	SetActionState(4.5f);
	mySprite.SetScale(1.0f, 1.0f);

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

void MiniSkeletonWarrior::Update(float & aDeltaTime, sf::Vector2f &aPosition)
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
		myAliveFlag = false;
		break;
	}

	mySprite.UpdateAnimation(aDeltaTime, myPosition, true);
}

void MiniSkeletonWarrior::Render(sf::RenderWindow & aWindow)
{
	mySprite.Flip((myDirection.x < (int)mySprite.GetSprite().getPosition().x) ? FlipSides::LEFT : FlipSides::RIGHT);
	//aWindow.draw(myHitbox);
	//aWindow.draw(myWeaponBB);
	mySprite.Render(aWindow);
}