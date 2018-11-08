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

void Sprite::SetScale(float aX, float aY)
{
	mySprite.setScale(sf::Vector2f(aX, aY));
}

void Sprite::Render(sf::RenderWindow & aWindow)
{
	aWindow.draw(mySprite);
}