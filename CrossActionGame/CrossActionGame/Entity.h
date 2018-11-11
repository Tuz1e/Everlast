#ifndef ENTITY_H
#define ENTITY_H

#include "Sprite.h"

class Entity
{
public:
	Entity();
	~Entity();

	virtual void LoadContent();
	virtual void Update(float &aDeltaTime);
	virtual void Render(sf::RenderWindow &aWindow);

protected:
	Sprite mySprite;
	sf::Vector2f mySpeed;
	sf::Vector2f myPosition;
};

#endif