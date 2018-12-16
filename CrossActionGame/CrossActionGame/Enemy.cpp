#include "pch.h"
#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::Update(float & aDeltaTime, sf::Vector2f & aPosition)
{
	if (myAnimateFlag)
	{
		mySprite.UpdateAnimation(aDeltaTime, myPosition, true);
	}
}
