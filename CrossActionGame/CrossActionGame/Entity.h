#ifndef ENTITY_H
#define ENTITY_H

#include "SpriteAnim.h"
#include "TextureContainer.h"
#include <iostream>

enum ActionState
{
	IDLE,
	WALK,
	ATTACK,
	HIT
};

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
	virtual void SetActionState(const float &anAnimationSpeed);
	virtual void HealthModifier(const int &someHealth);
	virtual sf::RectangleShape GetWeaponBB();
	virtual bool GetAttackingFlag();
	virtual int GetDamage();
	virtual int GetHealth();
	virtual sf::RectangleShape GetHitbox();


protected:
	sf::Vector2f
		mySpeed,
		myVelocity,
		myPosition;
	ActionState myActionState;
	int
		myHealth,
		myDamage;
	float myWeaponRange;
	std::vector<Textures*> mySpriteSheets;
	SpriteAnim mySprite;	
	bool myAnimateFlag;
	sf::RectangleShape 
		myWeaponBB,
		myHitbox;
	bool myAttackingFlag;
};

#endif