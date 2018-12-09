#include "pch.h"
#include "SpriteAnim.h"
#include <math.h>

SpriteAnim::SpriteAnim()
{
	myContentFolder = "Content";
}

SpriteAnim::~SpriteAnim()
{
	PtrDelete(myTexture);
	printf("\nDeleted SpriteAnim txtrptr.");
}

void SpriteAnim::LoadFromFile(const std::string &aFileName)
{
	//if (!myTexture.loadFromFile((myContentFolder + "/" + aFileName)))
	//{
	//	std::cout << "ERROR#Loading " + aFileName << std::endl;
	//}
	//mySprite.setTexture(myTexture);
	//myScale = mySprite.getScale();
}

sf::Texture *SpriteAnim::GetTexture()
{
	return myTexture;
}

void SpriteAnim::SetTexture(sf::Texture *aTexture)
{
	myTexture = aTexture;
	mySprite.setTexture(*aTexture);
	myScale = mySprite.getScale();
}

sf::Sprite& SpriteAnim::GetSprite()
{
	return mySprite;
}

void SpriteAnim::Flip(FlipSides aSide)
{
	if (aSide == FlipSides::LEFT)
	{
		mySprite.setScale(-myScale.x, myScale.y);
	}
	else
	{
		mySprite.setScale(myScale.x, myScale.y);
	}
}

void SpriteAnim::SetSprite(sf::Sprite aSprite)
{
	mySprite = aSprite;
	myCurrentFrame = 0;
}

void SpriteAnim::SetFrame(int * anIndex)
{
	myCurrentFrame = *anIndex;
}

void SpriteAnim::SetPosition(sf::Vector2f aPosition)
{
	mySprite.setPosition(aPosition);
}

void SpriteAnim::SetAnimation(int aRowCount, int aColumnCount, int aFrameCount, float aFramerate)
{
	myCurrentFrame = 0;

	myRowCount = aRowCount;
	myColumnCount = aColumnCount;
	myFrameCount = aFrameCount;
	myFramerate = aFramerate;

	//Sets the origin in the middle
	mySprite.setOrigin(myTexture->getSize().x / myColumnCount / 2.0f, myTexture->getSize().y / myRowCount / 2.0f);
}

void SpriteAnim::UpdateAnimation(float & aDeltaTime, sf::Vector2f &aPosition, bool aAnimateFlag)
{
	mySprite.setPosition(aPosition);

	if (aAnimateFlag)
	{
		myCurrentFrame += (myFramerate * aDeltaTime) / 60.0f;
	}

	if (myCurrentFrame >= myFrameCount || !aAnimateFlag)
	{
		myCurrentFrame = 0;
	}

	sf::IntRect tempIntegerRect(
		myTexture->getSize().x / myColumnCount * static_cast<int>(floor(myCurrentFrame)),
		myTexture->getSize().y * (myRowCount - 1),
		myTexture->getSize().x / myColumnCount,
		myTexture->getSize().y / myRowCount);

	mySprite.setTextureRect(tempIntegerRect);
}

void SpriteAnim::SetScale(float aX, float aY)
{
	mySprite.setScale(sf::Vector2f(aX, aY));
	myScale = sf::Vector2f(aX, aY);
}

void SpriteAnim::Render(sf::RenderWindow & aWindow)
{
	aWindow.draw(mySprite);
}