#ifndef ENTITY_H
#define ENTITY_H

#include "SpriteAnim.h"
#include "TextureContainer.h"
#include "pch.h"

class Entity
{
public:
	Entity();
	~Entity();

	virtual void LoadContent(TextureContainer *aTxtrContainer);
	virtual void Update(float &aDeltaTime);
	virtual void Render(sf::RenderWindow &aWindow);
	virtual void SetSpriteSheet(unsigned aTxtrIndex, unsigned anIndex, TextureContainer * aTxtrContainer);
	virtual void SetSpriteTexture(sf::Texture *aTexture);

	sf::Texture GetSpriteSheetTexture(const unsigned &anIndex);
	void SetPosition(sf::Vector2f aPos);

protected:
	SpriteAnim mySprite;
	sf::Vector2f
		mySpeed,
		myVelocity,
		myPosition;
	int myHealth;
	std::vector<Textures*> mySpriteSheets;
};

#endif