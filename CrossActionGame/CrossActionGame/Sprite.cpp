#include "pch.h"
#include "Sprite.h"

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
}

sf::Texture Sprite::GetTexture()
{
	return myTexture;
}

void Sprite::SetTexture(sf::Texture aTexture)
{
	myTexture = aTexture;
}

sf::Sprite Sprite::GetSprite()
{
	return mySprite;
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

	mySprite.setOrigin(myTexture.getSize().x / myColumnCount / 2, myTexture.getSize().y / 2);
}

void Sprite::UpdateAnimation(float & aDeltaTime, sf::Vector2f &aPosition, bool aAnimateFlag)
{
	mySprite.setPosition(aPosition);

		if (aAnimateFlag)
		{
			myCurrentFrame += aDeltaTime / myFramerate;
			//printf("Current Animation Frame: %f\n", myCurrentFrame);
		}

	if (myCurrentFrame >= myFrameCount)
	{
		myCurrentFrame = 0;
	}

	sf::IntRect tempIntegerRect(
		myTexture.getSize().x / myColumnCount * static_cast<int>(myCurrentFrame),
		myTexture.getSize().y * (myRowCount - 1),
		myTexture.getSize().x / myColumnCount,
		myTexture.getSize().y / myRowCount);

	mySprite.setTextureRect(tempIntegerRect);
}

void Sprite::SetScale(float aX, float aY)
{
	mySprite.setScale(sf::Vector2f(aX, aY));
}

void Sprite::Render(sf::RenderWindow & aWindow)
{
	aWindow.draw(mySprite);
}