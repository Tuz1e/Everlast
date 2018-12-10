#ifndef OBJECT_H
#define OBJECT_H

#include "Entity.h"

class Object : public Entity
{
public:
	Object
	(
		Textures *aTexture,
		const sf::Vector2f &aPosition,
		const sf::Vector2f &aSpeed,
		sf::Vector2f aScale = sf::Vector2f(1.0f, 1.0f)
	);
	~Object();

	SpriteAnim *GetSprite();
	Textures *GetTextures();

	//void SetSprite(sf::Texture *aTexture, sf::Vector2f &aPosition, sf::Vector2f &aSpeed, );
};

#endif