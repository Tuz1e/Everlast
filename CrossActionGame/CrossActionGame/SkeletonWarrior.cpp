#include "pch.h"
#include "SkeletonWarrior.h"


SkeletonWarrior::SkeletonWarrior()
{
	myHealth = 75;
	mySpeed = sf::Vector2f(2.5f, 2.5f);
	myPosition = sf::Vector2f(100.0f, 100.0f);
}


SkeletonWarrior::~SkeletonWarrior()
{
}

void SkeletonWarrior::LoadContent(TextureContainer & aTxtrContainer)
{
	SetSpriteSheet(SKELETON_WALK, WALK, &aTxtrContainer);

	mySprite.SetTexture(mySpriteSheets[WALK]->myTexture);
	mySprite.SetScale(3.0f, 3.0f);
	mySprite.SetAnimation(mySpriteSheets[WALK]->myRows, mySpriteSheets[WALK]->myColumns, mySpriteSheets[WALK]->myFrames, 9.0f);
}

void SkeletonWarrior::Update(float & aDeltaTime)
{
	mySprite.UpdateAnimation(aDeltaTime, myPosition, true);
}

void SkeletonWarrior::Render(sf::RenderWindow & aWindow)
{
	mySprite.Render(aWindow);
}
