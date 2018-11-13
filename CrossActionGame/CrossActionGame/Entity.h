#ifndef ENTITY_H
#define ENTITY_H

#include "SpriteAnim.h"

class Entity
{
public:
	Entity();
	~Entity();

	virtual void LoadContent(sf::Texture *aTexture);
	virtual void Update(float &aDeltaTime);
	virtual void Render(sf::RenderWindow &aWindow);

protected:
	SpriteAnim mySprite;
	sf::Vector2f
		mySpeed,
		myVelocity,
		myPosition;
};

#endif