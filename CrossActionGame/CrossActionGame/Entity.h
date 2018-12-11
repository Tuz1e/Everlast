#ifndef ENTITY_H
#define ENTITY_H

#include "SpriteAnim.h"
#include "TextureContainer.h"

class Entity
{
public:
	Entity();
	~Entity();

	virtual void Initialize();
	virtual void LoadContent(TextureContainer &aTxtrContainer);
	virtual void Update(float &aDeltaTime);
	virtual void Render(sf::RenderWindow &aWindow);
	virtual void SetSpriteSheet(unsigned aTxtrIndex, unsigned anIndex, TextureContainer * aTxtrContainer);
	virtual void SetSpriteTexture(sf::Texture *aTexture);
	virtual void SetPosition(sf::Vector2f aPos);
	virtual sf::Vector2f &GetPosition();
	virtual std::vector<Textures*> GetSpriteSheets();
	virtual void SetAnimation(int aRowCount, int aColumnCount, int aFrameCount, float aFramerate);
	virtual void UpdateAnimation(float & aDeltaTime, sf::Vector2f &aPosition, bool aAnimateFlag);
	virtual SpriteAnim GetSprite();
	virtual void SetAnimateFlag(bool aStatement);

protected:
	sf::Vector2f
		mySpeed,
		myVelocity,
		myPosition;
	int myHealth;
	std::vector<Textures*> mySpriteSheets;
	SpriteAnim mySprite;
	bool myAnimateFlag;
};

#endif