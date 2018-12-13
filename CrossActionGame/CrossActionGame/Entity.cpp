#include "pch.h"
#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::Initialize()
{
}

void Entity::LoadContent(TextureContainer &aTxtrContainer)
{
}

void Entity::Update(float & aDeltaTime)
{
	if (myAnimateFlag)
	{
		mySprite.UpdateAnimation(aDeltaTime, myPosition, true);
	}
}

void Entity::Render(sf::RenderWindow & aWindow)
{
	mySprite.Render(aWindow);
}

inline void Entity::SetSpriteSheet(unsigned aTxtrIndex, unsigned anIndex, TextureContainer * aTxtrContainer)
{
	mySpriteSheets.push_back(new Textures);
	mySpriteSheets[anIndex]->myTexture = aTxtrContainer->GetTexture(aTxtrIndex);
	mySpriteSheets[anIndex]->myRows = aTxtrContainer->GetRows(aTxtrIndex);
	mySpriteSheets[anIndex]->myColumns = aTxtrContainer->GetColumns(aTxtrIndex);
	mySpriteSheets[anIndex]->myFrames = aTxtrContainer->GetFrames(aTxtrIndex);
}

inline void Entity::SetSpriteTexture(sf::Texture *aTexture)
{
	mySprite.SetTexture(aTexture);
}

inline void Entity::SetPosition(sf::Vector2f aPos)
{
	myPosition = aPos;
}

sf::Vector2f & Entity::GetPosition()
{
	return myPosition;
}

std::vector<Textures*> Entity::GetSpriteSheets()
{
	return mySpriteSheets;
}

void Entity::SetAnimation(int aRowCount, int aColumnCount, int aFrameCount, float aFramerate)
{
	mySprite.SetAnimation(aRowCount, aColumnCount, aFrameCount, aFramerate);
}

void Entity::UpdateAnimation(float & aDeltaTime, sf::Vector2f & aPosition, bool aAnimateFlag)
{
	mySprite.UpdateAnimation(aDeltaTime, aPosition, aAnimateFlag);
}

SpriteAnim Entity::GetSprite()
{
	return mySprite;
}

void Entity::SetAnimateFlag(bool aStatement)
{
	myAnimateFlag = aStatement;
}

void Entity::SetActionState(const float &anAnimationSpeed)
{
	mySprite.SetTexture(mySpriteSheets[myActionState]->myTexture);
	mySprite.SetAnimation
	(
		mySpriteSheets[myActionState]->myRows,
		mySpriteSheets[myActionState]->myColumns,
		mySpriteSheets[myActionState]->myFrames,
		anAnimationSpeed
	);
}

void Entity::HealthModifier(int & someHealth)
{
	myHealth += someHealth;
}