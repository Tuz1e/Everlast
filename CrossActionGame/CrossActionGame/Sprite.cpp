#include "pch.h"
#include "Sprite.h"
#include <math.h>

Sprite::Sprite()
{
	myContentFolder = "Content";
}

Sprite::~Sprite()
{
}

void Sprite::LoadFromFile(const std::string &aFileName)
{
	if (!myTexture.loadFromFile((myContentFolder + "/" + aFileName)))
	{
		std::cout << "ERROR#Loading " + aFileName << std::endl;
	}
	mySprite.setTexture(myTexture);
	myScale = mySprite.getScale();
}

sf::Texture& Sprite::GetTexture()
{
	return myTexture;
}

void Sprite::SetTexture(sf::Texture aTexture)
{
	myTexture = aTexture;
	mySprite.setTexture(myTexture);
	myScale = mySprite.getScale();
}

sf::Sprite& Sprite::GetSprite()
{
	return mySprite;
}

void Sprite::Flip(FlipSides aSide)
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

void Sprite::SetSprite(sf::Sprite aSprite)
{
	mySprite = aSprite;
}

void Sprite::SetPosition(sf::Vector2f aPosition)
{
	mySprite.setPosition(aPosition);
}

void Sprite::SetAnimation(int aRowCount, int aColumnCount, int aFrameCount, float aFramerate)
{
	myCurrentFrame = 0;

	myRowCount = aRowCount;
	myColumnCount = aColumnCount;
	myFrameCount = aFrameCount;
	myFramerate = aFramerate;

	//Sets the origin in the middle
	mySprite.setOrigin(myTexture.getSize().x / myColumnCount / 2, myTexture.getSize().y / myRowCount / 2);
}

void Sprite::UpdateAnimation(float & aDeltaTime, sf::Vector2f &aPosition, bool aAnimateFlag)
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
		myTexture.getSize().x / myColumnCount * static_cast<int>(floor(myCurrentFrame)),
		myTexture.getSize().y * (myRowCount - 1),
		myTexture.getSize().x / myColumnCount,
		myTexture.getSize().y / myRowCount);

	mySprite.setTextureRect(tempIntegerRect);
}

void Sprite::SetScale(float aX, float aY)
{
	mySprite.setScale(sf::Vector2f(aX, aY));
	myScale = sf::Vector2f(aX, aY);
}

void Sprite::Render(sf::RenderWindow & aWindow)
{
	aWindow.draw(mySprite);
}