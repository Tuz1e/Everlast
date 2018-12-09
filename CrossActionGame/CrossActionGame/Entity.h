#ifndef ENTITY_H
#define ENTITY_H

#include "SpriteAnim.h"
#include "TextureContainer.h"

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
	virtual void SetPosition(sf::Vector2f aPos);
	virtual sf::Vector2f &GetPosition();
	virtual std::vector<Textures*> GetSpriteSheets();


	sf::Texture *GetSpriteSheetTexture(const unsigned &anIndex);
	SpriteAnim mySprite;
	sf::Vector2f myPosition;
	

protected:
	sf::Vector2f
		mySpeed,
		myVelocity;
	int myHealth;
	std::vector<Textures*> mySpriteSheets;
};

#endif