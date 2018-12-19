#include "pch.h"
#include "Instance.h"


Instance::Instance()
{
}


Instance::~Instance()
{
}

bool Instance::GetActiveFlag()
{
	return myActiveFlag;
}

void Instance::SetActiveFlag(bool aStatement)
{
	myActiveFlag = aStatement;
}

void Instance::SetActionState(const float & anAnimationSpeed)
{
	mySprite.SetTexture(mySpriteSheets[myInstanceState]->myTexture);
	mySprite.SetAnimation
	(
		mySpriteSheets[myInstanceState]->myRows,
		mySpriteSheets[myInstanceState]->myColumns,
		mySpriteSheets[myInstanceState]->myFrames,
		anAnimationSpeed
	);
}
