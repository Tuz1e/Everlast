#include "pch.h"
#include "SkeletonWarrior.h"
#include "PostNord.h"
#include <cmath>

SkeletonWarrior::SkeletonWarrior()
{
	myHealth = 75;
	mySpeed = sf::Vector2f(2.0f, 2.0f);
	myPosition = sf::Vector2f(100.0f, 100.0f);
	myRecogDistance = 10.0f;
	myActionState = ActionState::IDLE;
}

SkeletonWarrior::~SkeletonWarrior()
{
}

void SkeletonWarrior::Initialize()
{

}

void SkeletonWarrior::LoadContent(TextureContainer & aTxtrContainer)
{
	SetSpriteSheet(SKELETON_IDLE, IDLE, &aTxtrContainer); //Sets the idle animation
	SetSpriteSheet(SKELETON_WALK, WALK, &aTxtrContainer); //Sets the walking animation

	mySprite.SetTexture(mySpriteSheets[myActionState]->myTexture);
	mySprite.SetScale(3.0f, 3.0f);
	mySprite.SetAnimation
	(
		mySpriteSheets[myActionState]->myRows, 
		mySpriteSheets[myActionState]->myColumns, 
		mySpriteSheets[myActionState]->myFrames, 
		9.0f
	);
}

void SkeletonWarrior::Update(float & aDeltaTime, sf::Vector2f &aPosition)
{
	myVelocity.x = aPosition.x - myPosition.x;
	myVelocity.y = aPosition.y - myPosition.y;
	float tempHypo = sqrt((myVelocity.x * myVelocity.x) + (myVelocity.y * myVelocity.y)); //Gets the hypotenuse

	if (tempHypo <= myRecogDistance) 
	{
		if (tempHypo != 0) 
		{
			myPosition.y += aDeltaTime * mySpeed.y * (myVelocity.y / tempHypo);
			myPosition.x += aDeltaTime * mySpeed.x * (myVelocity.x / tempHypo);
		}
	}

	mySprite.UpdateAnimation(aDeltaTime, myPosition, true);
}

void SkeletonWarrior::Render(sf::RenderWindow & aWindow)
{
	mySprite.Render(aWindow);
}

bool SkeletonWarrior::WithinRecogDistance(sf::Vector2f aPlayerPos, sf::Vector2f aIsMyPos)
{
	if (((aIsMyPos.x - aPlayerPos.x) + (aIsMyPos.y - aPlayerPos.y)) >= myRecogDistance) 
	{
		return true;
	}
	return false;
}
