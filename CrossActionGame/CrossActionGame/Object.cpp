#include "pch.h"
#include "Object.h"

Object::Object
(
	Textures *aTexture,
	const sf::Vector2f &aPosition,
	const sf::Vector2f &aSpeed,
	sf::Vector2f aScale = sf::Vector2f(1.0f, 1.0f)
)
{
	myTexture = aTexture;
	mySprite.SetTexture(aTexture->myTexture);
	mySprite.SetPosition(aPosition.x, aPosition.y);
	mySprite.SetScale(aScale.x, aScale.y);
}

Object::~Object()
{
}

SpriteAnim * Object::GetSprite()
{
	return &mySprite;
}

Textures * Object::GetTextures()
{
	return myTexture;
}